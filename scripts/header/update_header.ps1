# Updating Git tag and hash...
Write-Host "Updating Git tag and hash..."

# Check if header file path is provided
if ($args.Length -eq 0) {
    Write-Host "Usage: [HeaderFilePath]"
    exit
}

# Get the current git tag and hash
$GIT_TAG = & git describe --tags --abbrev=0
$GIT_HASH = & git rev-parse --short HEAD

# Use powershell to replace the GIT_TAG and GIT_HASH in the header file
(Get-Content $args[0]) -replace '#define GIT_TAG .*', "#define GIT_TAG `"$GIT_TAG`"" | Set-Content $args[0]
(Get-Content $args[0]) -replace '#define GIT_HASH .*', "#define GIT_HASH `"$GIT_HASH`"" | Set-Content $args[0]

Write-Host "Git tag is $GIT_TAG"
Write-Host "Git hash is $GIT_HASH"