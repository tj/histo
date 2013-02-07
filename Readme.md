# Histo

  Plot charts in the terminal with arbitrary streaming
  or non-streaming data.

```
$ histo < data.txt
```

  ![terminal histogram](http://i.cloudup.com/1359230211455.54961fc5a2db5b350ca5f1f89b8d37b3.png)

## Features

  - simple input via __stdin__
  - simple C API for integration in your tools
  - supports static or streaming data
  - adjusts to terminal width and height
  - adjusts x-axis labels to the integer size
  - negative values reflect as shaded blocks

## Use-cases

  - cpu usage
  - memory usage
  - load averages
  - ...

## Installation

  With [cpm](https://github.com/visionmedia/cpm):

```
$ cpm install visionmedia/histo
```

  Or via git clone:

```
$ cd /tmp && git clone git://github.com/visionmedia/histo.git --depth 1 && cd histo && make install
```

## Examples

  `histo(1)` simply reads from stdin, so it works well with
  streaming or non-streaming data, from any data source. This
  repo includes some example files in `./examples`, as well
  as some example shell scripts for streaming input.

### Static input

  `histo(1)` simply reads from stdin, so it's easy to throw static
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
done | histo
```

## Screenshots

  Negative values are shown as shaded blocks:

  ![histogram with negative values](http://i.cloudup.com/1359230211455.54961fc5a2db5b350ca5f1f89b8d37b3.png)

  Adjusts properly to the size of the terminal:

  ![size adjustment](http://i.cloudup.com/1359230206899.2c598d4a91643490bdb7be5d781b9e7c.png)

  ![tall](http://i.cloudup.com/1359230209532.d602f47204f04da4448460a579ecbfa3.png)

# License

  MIT
