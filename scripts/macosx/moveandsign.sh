#!/bin/bash
# Utility script to be ran post-install to move and codesign files

# Define paths
TAYST_DIR=~/Library/Application\ Support/TaystJK
JEDI_DIR=~/Library/Application\ Support/Steam/steamapps/common/Jedi\ Academy/JediAcademy
TAYST_APP=$TAYST_DIR/taystjk.arm64.app

# Check TaystJK destination directory exists
if [ ! -d "$TAYST_DIR" ]; then
    echo "Error: TaystJK directory not found at $TAYST_DIR"
    exit 1
fi

# Check new files are present in Jedi Academy directory
if [ ! -d "$JEDI_DIR/taystjk.arm64.app" ]; then
    echo "Error: Jedi Academy files not found. Make sure the game is installed through Steam."
    exit 1
fi

# Remove existing TaystJK files
rm -rf "$TAYST_DIR/taystjk.arm64.app" "$TAYST_DIR/taystjk/" "$TAYST_DIR/taystjkded.arm64"

# Move new files to TaystJK folder
mv "$JEDI_DIR"/* "$TAYST_DIR"

# Remove quarantine attribute
xattr -r -d com.apple.quarantine "$TAYST_APP"

# Sign the application
codesign --force --deep --sign - "$TAYST_APP"

echo "TaystJK setup completed successfully!"