files="files"

for file in "$files"/*; do
	if [ -f $file ]; then
		response="responses/$(basename "$file")"
		if [ -f $response ]; then
			res="$file - $response"
			diffs=$(diff $file $response)
			if [ -z "$diffs" ]; then
				res="OK $res"
			else
				res="BAD $res"
			fi
			echo $res
		fi
	fi
done
