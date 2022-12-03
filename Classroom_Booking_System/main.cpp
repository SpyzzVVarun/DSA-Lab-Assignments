#include "functions.h"

int main()
{
    cout << "\n\n\nInitializing Database with Random Entries....\n\n";
    bookRoom(4005, {1,1}, 1, "DA242", "AA");
    bookRoom(4005, {1,1}, 3, "DA241", "RG");
    bookRoom(4005, {1,1}, 6, "DA251", "SSN");
    bookRoom(4104, {1,1}, 8, "DA241", "RG");
    updateRoomDetails(4005, 50, 1, 0);
    updateRoomDetails(4104, 30, 0, 0);
    
    // Menu driven program for Classroom Booking System
    while (1)
    {
        int choice, room, time, capacity;
        bool projector, ac;
        pair<int,int> date;
        string course, instructor;

        cout << "@@==========================================================@@";
        cout << endl;
        cout << "||                                                          ||";
        cout << endl;
        cout << "||                   Classroom Booking System               ||";
        cout << endl;
        cout << "||                                                          ||";
        cout << endl;
        cout << "@@==========================================================@@";
        cout <<endl;
        cout <<endl;
        cout<<"1.Room Schedule"<<endl;
        cout<<"2.Book Room"<<endl;
        cout<<"3.Cancel Booking"<<endl;
        cout<<"4.Enter Room Details"<<endl;
        cout<<"5.Display Room Details"<<endl;
        cout<<"6.Exit "<<endl;
        cout <<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter Room Number: ";
            cin >> room;
            cout <<"Enter Date (dd/mm): ";
            cin >> date.first;
            cin >> date.second;
            printRoomSchedule(room, date);
            break;
        case 2:
            cout<<"Enter Room Number: ";
            cin >> room;
            cout <<"Enter Date (dd/mm): ";
            cin >> date.first;
            cin >> date.second;
            cout<<"Enter Time Slot: ";
            cin >> time;
            cout <<"Enter Course: ";
            cin >> course;
            cout <<"Enter Course Instructor: ";
            cin >> instructor;
            bookRoom(room, date, time, course, instructor);
            break;
        case 3:
            cout<<"Enter Room Number: ";
            cin >> room;
            cout <<"Enter Date (dd/mm): ";
            cin >> date.first;
            cin >> date.second;
            cout<<"Enter Time Slot: ";
            cin >> time;
            cancelBooking(room, date, time);
            break;
        case 4:
            cout<<"Enter Room Number: ";
            cin >> room;
            cout<<"Enter Capacity: ";
            cin >> capacity;
            cout<<"Is there a projector? (0/1): ";
            cin >> projector;
            cout<<"Is there an AC? (0/1): ";
            cin >> ac;
            updateRoomDetails(room, capacity, projector, ac);
            break;
        case 5:
            cout<<"Enter Room Number: ";
            cin >> room;
            printRoomDetails(room);
            break;
        case 6:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;  
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}