echo "Updating Git tag and hash..."

# Check if header file path is provided
if [ -z "$1" ]
then
    echo "Usage: $0 [HeaderFilePath]"
    exit 1
fi

# Get the current git tag and hash
GIT_TAG=$(git describe --tags --abbrev=0)
GIT_HASH=$(git rev-parse --short HEAD)

# Use sed to replace the GIT_TAG and GIT_HASH in the header file
sed -i -e "s/#define GIT_TAG .*/#define GIT_TAG \"$GIT_TAG\"/g" $1
sed -i -e "s/#define GIT_HASH .*/#define GIT_HASH \"$GIT_HASH\"/g" $1

echo "Git tag is $GIT_TAG"
echo "Git hash is $GIT_HASH"