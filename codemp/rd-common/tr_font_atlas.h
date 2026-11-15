#pragma once

#include <algorithm>
#include <cassert>
#include <cstring>
#include <vector>

// CPU mirror of an append-only RGBA font atlas. Upload full-width dirty rows
// so all renderers can consume one contiguous span without a packing buffer.
struct FontAtlasBuffer {
	int size;
	std::vector<unsigned char> pixels;
	int top, bottom;
	bool dirty;

	explicit FontAtlasBuffer(int dimension)
		: size(dimension), pixels(dimension * dimension * 4, 0), top(0), bottom(0), dirty(false) {}

	// Returns true only when this page first enters the pending upload queue.
	bool Update(int x, int y, int width, int height, const unsigned char* rgba) {
		assert(x >= 0 && y >= 0 && width > 0 && height > 0 && x + width <= size && y + height <= size);
		for (int row = 0; row < height; row++)
			std::memcpy(pixels.data() + ((y + row) * size + x) * 4, rgba + row * width * 4, width * 4);
		const bool first = !dirty;
		if (first) {
			top = y;
			bottom = y + height;
		} else {
			top = std::min(top, y);
			bottom = std::max(bottom, y + height);
		}
		dirty = true;
		return first;
	}

	const unsigned char* Data() const { return pixels.data() + top * size * 4; }
	int Height() const { return bottom - top; }
	void Uploaded() { dirty = false; }
};
