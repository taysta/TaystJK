#!/bin/bash -ex
#
# TaystJK server run script.
#

# Set variables
TJK_DIR="/opt/taystjk"
TJK_MOD="${TJK_MOD:-TaystJK}"
TJK_ARCH="${TJK_ARCH:-i386}"
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

# Launch TaystJK
mkdir -p `dirname "$TJK_LOG"`
export HOME="$TJK_HOMEPATH"
umask 0002
$TJK_BIN $TJK_OPTS 2>&1 | tee -a "$TJK_LOG" &

# Wait for it while listening to signals
wait $!
