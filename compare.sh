files="./files"

for file in "$files"/*; do
  if [ -f $file ]; then
    response="responses/$(basename "$file")"
    diffs=$(diff $file $response)
    echo "$file - $response $diffs"
  fi
done
