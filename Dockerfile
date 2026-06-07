# Builder image
FROM ubuntu:22.04 as builder

# Install build tools and libraries
RUN dpkg --add-architecture i386 &&\
	apt-get -q update &&\
	DEBIAN_FRONTEND="noninteractive" apt-get -q install -y -o Dpkg::Options::="--force-confnew" --no-install-recommends build-essential gcc-multilib g++-multilib cmake libjpeg-dev libjpeg-dev:i386 libpng-dev libpng-dev:i386 zlib1g-dev zlib1g-dev:i386 &&\
	rm -rf /var/lib/apt/lists/*

# Copy sources
COPY . /usr/src/taystjk

# Build i386 arch
RUN mkdir /usr/src/taystjk/build.i386 &&\
	cd /usr/src/taystjk/build.i386 &&\
	cmake -DCMAKE_TOOLCHAIN_FILE=cmake/Toolchains/linux-i686.cmake \
		-DCMAKE_INSTALL_PREFIX=/opt \
		-DBuildMPCGame=OFF -DBuildMPEngine=OFF -DBuildMPRdVanilla=OFF -DBuildMPUI=OFF -DBuildMPRend2=OFF \
		.. &&\
	make &&\
	make install

# Build x86_64 arch
RUN mkdir /usr/src/taystjk/build.x86_64 &&\
	cd /usr/src/taystjk/build.x86_64 &&\
	cmake -DCMAKE_INSTALL_PREFIX=/opt \
		-DBuildMPCGame=OFF -DBuildMPEngine=OFF -DBuildMPRdVanilla=OFF -DBuildMPUI=OFF -DBuildMPRend2=OFF \
		.. &&\
	make &&\
	make install


# Server image
FROM ubuntu:22.04

# Install utilities and libraries
RUN dpkg --add-architecture i386 &&\
	apt-get -q update &&\
	DEBIAN_FRONTEND="noninteractive" apt-get -q install -y -o Dpkg::Options::="--force-confnew" --no-install-recommends socat libstdc++6 libstdc++6:i386 zlib1g zlib1g:i386 &&\
	rm -rf /var/lib/apt/lists/*

# Copy binaries and scripts
RUN mkdir -p /opt/taystjk/cdpath/base /opt/taystjk/basepath /opt/taystjk/homepath
COPY --from=builder /opt/JediAcademy/taystjkded.* /opt/taystjk/
COPY --from=builder /opt/JediAcademy/base/ /opt/taystjk/cdpath/base/
COPY --from=builder /opt/JediAcademy/TaystJK/ /opt/taystjk/cdpath/TaystJK/
COPY scripts/docker/*.sh /opt/taystjk/
COPY scripts/docker/server.cfg /opt/taystjk/cdpath/base/
COPY scripts/docker/server.cfg /opt/taystjk/cdpath/TaystJK/
RUN chmod +x /opt/taystjk/taystjkded.* /opt/taystjk/*.sh

# Execution
ENV TJK_OPTS="+exec server.cfg"
EXPOSE 29070/udp
HEALTHCHECK --interval=10s --timeout=9s --retries=6 CMD ["/opt/taystjk/healthcheck.sh"]
CMD ["/opt/taystjk/run.sh"]
