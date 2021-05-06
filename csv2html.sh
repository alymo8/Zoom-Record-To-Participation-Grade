#!/bin/bash
echo "<TABLE>" >> $2
cat $1 | sed -e 's/$/<\/TD><\/TR>/g' -e 's/^/<TR><TD>/g' -e 's/,/<\/TD><TD>/g' >> $2
echo "</TABLE>" >> $2
