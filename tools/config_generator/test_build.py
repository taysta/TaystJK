#!/usr/bin/env python3
"""Regression coverage for how build.py reads the bundled server configs."""

import unittest

from build import unwritten_server_statements


class ServerStatementTests(unittest.TestCase):
    def test_statements_the_generator_writes_itself_pass(self):
        statements = [
            {"t": "exec", "file": "bans"}, {"t": "exec", "file": "votes"},
            {"t": "exec", "file": "default"}, {"t": "cmd", "text": "map mp/ffa3"},
            {"t": "cvar", "name": "sv_fps", "value": "40", "note": None},
        ]
        self.assertEqual(unwritten_server_statements(statements), [])

    def test_a_new_exec_or_command_is_reported_not_dropped(self):
        extra = [{"t": "exec", "file": "motd"}, {"t": "cmd", "text": "addbot kyle 3 red"}]
        self.assertEqual(unwritten_server_statements(extra), extra)


if __name__ == "__main__":
    unittest.main()
