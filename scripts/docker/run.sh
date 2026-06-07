#!/bin/bash -ex
#
# TaystJK server run script.
#

# Set variables
TJK_DIR="/opt/taystjk"
TJK_MOD="${TJK_MOD:-taystjk}"
TJK_ARCH="${TJK_ARCH:-x86_64}"
TJK_CDPATH="$TJK_DIR/cdpath"
TJK_BASEPATH="$TJK_DIR/basepath"
TJK_HOMEPATH="$TJK_DIR/homepath"
TJK_OPTS="+set dedicated 2 +set net_port 29070 +set fs_cdpath $TJK_CDPATH +set fs_basepath $TJK_BASEPATH +set fs_homepath $TJK_HOMEPATH +set fs_game $TJK_MOD $TJK_OPTS"
TJK_BIN="$TJK_DIR/taystjkded.$TJK_ARCH"
TJK_LOG="$TJK_HOMEPATH/$TJK_MOD/taystjk_server.log"

# Load functions
. "$TJK_DIR/functions.sh"

# Remove nav files
find "$TJK_DIR" -name '*.nav' -delete

# Register signal handler
trap 'rcon quit' SIGTERM

# Validate Jedi Academy assets
for pk3 in assets0.pk3 assets1.pk3 assets2.pk3 assets3.pk3; do
    if [ ! -f "$TJK_CDPATH/base/$pk3" ]; then
        echo "Missing required Jedi Academy asset: $TJK_CDPATH/base/$pk3"
        echo "Mount your Jedi Academy base assets into $TJK_CDPATH/base"
        exit 1
    fi
done

# Launch TaystJK
mkdir -p "$(dirname "$TJK_LOG")"
export HOME="$TJK_HOMEPATH"
umask 0002
"$TJK_BIN" $TJK_OPTS 2>&1 | tee -a "$TJK_LOG" &

# Wait for it while listening to signals
wait $!
