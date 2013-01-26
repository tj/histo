
# Histo

  Plot histograms in the terminal with arbitrary streaming
  or non-streaming data. Also provides a C API.

## Examples

  `histo(1)` simply reads from stdin, so it works well with
  streaming or non-streaming data, from any data source. This
  repo includes some example files in `./examples`, as well
  as some example shell scripts for streaming input.

### Static input

  `hist(1)` simply reads from stdin, so it's easy to throw static
  data at it for quick analysis:

```
1
4
5
12
8
15
18
20
5
2
1
5
2
10
2
```

  Displayed with:

```
$ histo < example.txt
```

### Dynamic input

  You may stream data to `histo(1)` and tell it to quit with __EOF__,
  for example here's a small shell script to generate some random
  data:

```sh
while true; do
  echo $RANDOM
  sleep .5
done
```

  Display with:

```
$ sh example.sh | histo
```

# License

  MIT
