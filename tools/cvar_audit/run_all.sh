#!/usr/bin/env bash
# Every check CI runs, in order. Used by the docs-branch workflow, by the scheduled run
# that lives on the source branch, and by anyone working locally.
#
#   tools/cvar_audit/run_all.sh [--ref <git ref>]
#
# --ref is the source ref to compare registrations against; it defaults to origin/master.
set -uo pipefail

ref="origin/master"
while [ $# -gt 0 ]; do
  case "$1" in
    --ref) ref="$2"; shift 2 ;;
    *) echo "unknown argument: $1" >&2; exit 2 ;;
  esac
done

cd "$(dirname "$0")/../.."

failed=0
run() {
  local name="$1"; shift
  printf '\n=== %s ===\n' "$name"
  if "$@"; then
    return 0
  fi
  printf '!!! %s FAILED\n' "$name"
  failed=1
}

run "extractor tests"        python3 tools/cvar_audit/test_extract.py
run "provenance tests"       python3 tools/cvar_audit/test_provenance.py
run "reference app tests"    node    tools/cvar_audit/test_reference_app.js
run "site search tests"      node    tools/cvar_audit/test_site_search.js
run "liquid templates"       python3 tools/cvar_audit/test_liquid.py
run "record validation"      python3 tools/cvar_audit/validate.py
run "generated pages"        python3 tools/cvar_audit/check_generated.py
run "source drift"           python3 tools/cvar_audit/check_drift.py --ref "$ref"

printf '\n'
if [ "$failed" -ne 0 ]; then
  echo "One or more checks failed."
  exit 1
fi
echo "All checks passed."
