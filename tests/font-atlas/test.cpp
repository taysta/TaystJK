#undef NDEBUG
#include "../../codemp/rd-common/tr_font_atlas.h"
#include <cstdio>

int main() {
	FontAtlasBuffer atlas(16);
	std::vector<unsigned char> gpu(16 * 16 * 4, 0);
	const unsigned char first[] = {1,2,3,4,5,6,7,8};
	const unsigned char second[] = {9,10,11,12};
	int uploads = 0, queueEntries = 0;
	auto flush = [&]() {
		if (!atlas.dirty) return;
		std::memcpy(gpu.data() + atlas.top * 16 * 4, atlas.Data(), atlas.Height() * 16 * 4);
		atlas.Uploaded();
		uploads++;
	};
	queueEntries += atlas.Update(2, 7, 2, 1, first);
	queueEntries += atlas.Update(15, 15, 1, 1, second);
	queueEntries += atlas.Update(0, 0, 1, 1, second);
	assert(queueEntries == 1 && atlas.top == 0 && atlas.Height() == 16);
	assert(gpu[7 * 16 * 4 + 2 * 4] == 0); // no upload while glyphs are built
	flush();
	assert(uploads == 1 && gpu == atlas.pixels);
	for (int i = 0; i < 10000; i++) flush();
	assert(uploads == 1); // warm frames do no uploads
	assert(atlas.Update(8, 8, 1, 1, second));
	assert(atlas.top == 8 && atlas.Height() == 1);
	flush();
	assert(uploads == 2 && gpu == atlas.pixels);
	assert(std::memcmp(gpu.data() + (7 * 16 + 2) * 4, first, sizeof(first)) == 0);
	assert(gpu[4 * 16 * 4] == 0); // untouched padding remains transparent
	std::puts("Atlas tests passed: coalescing, edge slots, padding, partial flushes, warm frames and existing glyph preservation.");
}
