files="./files"

for file in "$files"/*; do
  if [ -f $file ]; then
    response="responses/$(basename "$file")"
    diffs=$(diff $file $response)
    res="$file - $response"
    if [ -z "$diffs" ]; then
      res="OK $res"
    else
      res="BAD $res"
    fi
    echo $res
  fi
done
