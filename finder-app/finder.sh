filesdir=$1
searchstr=$2

if [ $# -ne 2 ]; then
    echo "Missing parameters"
    exit 1
elif [ ! -d $filesdir ]; then
    echo "Directory does not exist"
    exit 1
else
    echo "The number of files are $(find $filesdir -type f | wc -l) and the number of matching lines are $(grep -r $searchstr $filesdir | wc -l)"
    exit 0
fi