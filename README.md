# Zoom-Record-To-Participation-Grade
This project generates students grades for students based on their attendance in the lab sessions during the semester

Zoom records are generated in one of two forms, with enter and exit time, or without both. The code will differenciate both forms, and only select the fields we want to output.

fixformat.sh gets as first argument the directory to select files from. It takes all files with the format <lab.?> ignoring case and output all the records to the second argument as a single file, after only selecting the fields we want to use using sed and awk. 

![Screenshot (57)](https://user-images.githubusercontent.com/76274266/117364955-438d7100-aec7-11eb-8511-aba9e1b598e7.png)

labapp.c, zoomrec.c and zoomrecs.c are used to Each student will have his own record in a line of the file, and will have his participation percentage counted. zoomrec.h contains the student struct, that is created for each student, that keeps his name, email, and durations attended, and each student will be found using his email, to be assigned his participation grade.

Here is the output file after executing labapp

![Screenshot (59)](https://user-images.githubusercontent.com/76274266/117366417-61f46c00-aec9-11eb-977f-4d39d3b4e497.png)

csv2html.sh transforms the input file to an html file.

![Screenshot (87)](https://user-images.githubusercontent.com/76274266/117366573-a1bb5380-aec9-11eb-9de8-4554e98e0f33.png)
