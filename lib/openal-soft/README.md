# OpenAL Soft runtime

TaystJK builds and packages OpenAL Soft 1.25.2 from the same pinned source on
Windows, macOS, and Linux. OpenAL is still an opt-in sound backend at runtime
(`s_UseOpenAL` defaults to `0`).

The tagged upstream archive is fetched during CMake configuration and is pinned
by SHA-256 in the top-level `CMakeLists.txt`. `ALSOFT_EAX=ON` is forced so EAL
environments can use EAX on every platform.
OpenAL Soft 1.25.2 requires a complete C++20 standard library; GCC builds use
GCC 12 or newer (the Ubuntu CI jobs explicitly select GCC 12). Older GCC
defaults to `UseInternalOpenAL=OFF` and uses the system OpenAL instead; without
one the client builds without the OpenAL backend. MinGW builds always use the
software mixer.

The Windows build keeps the established runtime names: `OpenAL32.dll` for x86
and `OpenAL32.x86_64.dll` for x64. The architecture-qualified x64 name prevents
a TaystJK installation from colliding with Jedi Academy's legacy
`OpenAL32.dll`; CMake generates the correspondingly named import library from
the same source-built target.

The legacy Windows XP compatibility workflow disables the optional OpenAL
backend because its v141_xp toolchain does not provide the C++20 standard
library required by OpenAL Soft 1.25.2. Normal Windows builds use the fetched,
source-built runtime.
