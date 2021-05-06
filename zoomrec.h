
struct ZoomRecord
{
char email[60]; // email of the student
char name[60]; // name of the student
int durations[9]; // duration for each lab.
struct ZoomRecord *next;
};

struct ZoomRecord* addZoomRecord(struct ZoomRecord* head,char* name, char* email,char *letter, char* duration);
void generateAttendance(FILE* out, struct ZoomRecord *head);
