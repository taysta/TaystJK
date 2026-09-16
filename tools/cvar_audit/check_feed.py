#!/usr/bin/env python3
"""Validate HTML text constructs in the built Atom feed (run after Jekyll)."""

import sys
import xml.etree.ElementTree as ET
from pathlib import Path


def check(path: Path) -> None:
    root = ET.parse(path).getroot()
    contents = root.findall("{http://www.w3.org/2005/Atom}entry/{http://www.w3.org/2005/Atom}content")
    if not contents:
        raise ValueError("Feed has no entry content")
    for content in contents:
        if content.get("type") != "html" or len(content) or not (content.text or "").strip():
            raise ValueError("Atom HTML content must be escaped character data, not nested XML elements")
    print(f"Atom HTML content is valid in {len(contents)} entries")


if __name__ == "__main__":
    check(Path(sys.argv[1] if len(sys.argv) > 1 else "_site/devlog/feed.xml"))
