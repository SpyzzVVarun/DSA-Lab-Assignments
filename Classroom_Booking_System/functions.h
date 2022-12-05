#include "global.h"

struct room_details
{
    int capacity;
    bool projector;
    bool ac;
};

map<int, map<pair<int,int>, map<int, pair<string,string>>>> room_schedule; // <room number, <date, <time slot, <course,instructor>>>
map<int ,room_details> room; // <room_number, {capacity, projector, AC}>


void initRoomSchedule(int room, pair<int, int> date)
{
    if (room_schedule.find(room) == room_schedule.end()) 
    {
        for(int i=0;i<10;++i)
        {
            room_schedule[room][date][i] = {"Vacant","None"};
        }
    }
    else if (room_schedule[room].find(date) == room_schedule[room].end()) 
    {
        for(int i=0;i<10;++i)
        {
            room_schedule[room][date][i] = {"Vacant","None"};
        }
    }
}

void printHelperFirst(int LEN, int room, pair<int, int> date, int i)
{
    int len = LEN - room_schedule[room][date][i].first.length();
    int extra = (len%2==0)?0:1;
    len = (len%2==0)?len/2:(len+1)/2;
    for(int i=0;i<len;i++) cout << " "; 
    cout << room_schedule[room][date][i].first; 
    for(int i=0;i<len-extra;i++) cout << " ";
    cout << " |";
}

void printHelperSecond(int LEN, int room, pair<int, int> date, int i)
{
    int len = LEN - room_schedule[room][date][i].second.length();
    int extra = (len%2==0)?0:1;
    len = (len%2==0)?len/2:(len+1)/2;
    for(int i=0;i<len;i++) cout << " "; 
    cout << room_schedule[room][date][i].second; 
    for(int i=0;i<len-extra;i++) cout << " ";
    cout << " |";
}

void printRoomSchedule(int room, pair<int, int> date)
{
    initRoomSchedule(room, date);
     
    cout << endl;
    for(int i=0;i<18;i++) cout << " ";
    cout << "Room Number: " << room;
    for(int i=0;i<19;i++) cout << " ";
    cout << endl;

    for(int i=0;i<21;i++) cout << " ";
    cout << "Date: " << date.first << "/" << date.second;
    for(int i=0;i<22;i++) cout << " ";
    cout << endl;

    cout << "-----------------------------------------------------" << endl; 
    cout << "| Slots |             Course           | Instructor |" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "| 08-09 | ";
    printHelperFirst(28, room, date, 0); 
    printHelperSecond(11, room, date, 0);
    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "| 09-10 | ";
    printHelperFirst(28, room, date, 1); 
    printHelperSecond(11, room, date, 1);
    cout<< endl;
    for(int j=10;j<=17;++j)
    { 
        cout << "-----------------------------------------------------" << endl;
        cout << "| " << j << "-" << j+1 << " | ";
        printHelperFirst(28, room, date, j-8); 
        printHelperSecond(11, room, date, j-8);
        cout<< endl;
    }
    cout << "-----------------------------------------------------" << endl;
    cout << "\n\n\n\n\n\n";

}

void bookRoom(int room, pair<int, int> date, int time, string course, string instructor)
{
    initRoomSchedule(room, date);
    if (room_schedule[room][date][time].first == "Vacant")
    {
        room_schedule[room][date][time].first = course;
        room_schedule[room][date][time].second = instructor;
    }
    else
    {
        cout << "\n\nRoom is already Booked for " << room_schedule[room][date][time].first << " by " << room_schedule[room][date][time].second << "\n" << endl;
    }  
}

void bookRecurrHelper(int mod, int effective_date, int room, int time, string course, string instructor)
{
    for(int i=effective_date+1; i<=90; ++i)
    {
        if (i%7==mod) 
        {
            if ((i>=1) && (i<=31)) bookRoom(room, {i, 1}, time, course, instructor);
            else if ((i>=32) && (i<=59)) bookRoom(room, {i-31, 2}, time, course, instructor);
            if ((i>=60) && (i<=90)) bookRoom(room, {i-59, 3}, time, course, instructor);
        }
    }
}

void printRoomDetails(int room_number)
{
    cout << endl;
    cout << "Room Number: " << room_number << endl;
    cout << "Room Capacity: " << room[room_number].capacity << endl;
    cout << endl;
    cout << "Q) Is there a projector in the room?\n";
    if (room[room_number].projector == 0) cout << "A) No"; 
    else cout << "A) Yes";
    cout << endl;
    cout << "Q) Is there an AC in the room?\n";
    if (room[room_number].ac == 0) cout << "A) No"; 
    else cout << "A) Yes";
    cout << endl;
    cout << "\n\n\n\n\n\n";
}

void updateRoomDetails(int room_number, int capacity, bool projector, bool ac)
{
    room[room_number].capacity = capacity;
    room[room_number].projector = projector;
    room[room_number].ac = ac;
}

void cancelBooking(int room_number, pair<int, int> date,int time, string instructor)
{
    if ((room_schedule[room_number][date][time].second == instructor) || (room_schedule[room_number][date][time].second == "None"))
    {
        room_schedule[room_number][date][time] = {"Vacant","None"};
    }
    else cout << "User does not have the necessary privileges to cancel this booking.\n\n";
}

void cancelRecurrHelper(int mod, int effective_date, int room, int time, string instructor)
{
    for(int i=effective_date+1; i<=90; ++i)
    {
        if (i%7==mod) 
        {
            if ((i>=1) && (i<=31)) cancelBooking(room, {i, 1}, time, instructor);
            else if ((i>=32) && (i<=59)) cancelBooking(room, {i-31, 2}, time, instructor);
            if ((i>=60) && (i<=90)) cancelBooking(room, {i-59, 3}, time, instructor);
        }
    }
}