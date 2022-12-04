#include "functions.h"

int main()
{
    cout << "\n\n\nInitializing Database with Random Entries....\n\n";
    bookRecurrHelper(2, 1, 4005, 1, "DA241", "RG");
    bookRecurrHelper(2, 1, 4005, 2, "DA231", "DRN");
    bookRecurrHelper(2, 1, 4005, 3, "DA251", "SSN");
    bookRecurrHelper(3, 1, 4005, 1, "DA241", "RG");
    bookRecurrHelper(3, 1, 4005, 3, "DA251", "SSN");
    bookRecurrHelper(4, 1, 4005, 1, "DA241", "RG");
    bookRecurrHelper(4, 1, 4005, 3, "DA251", "SSN");
    bookRecurrHelper(5, 1, 4005, 1, "DA231", "DRN");
    bookRecurrHelper(5, 1, 4005, 3, "DA251", "SSN");
    bookRecurrHelper(6, 1, 4005, 0, "DA231", "DRN");
    bookRecurrHelper(6, 1, 4005, 1, "DA231", "DRN");
    bookRecurrHelper(6, 1, 4005, 2, "DA251", "SSN");

    updateRoomDetails(4005, 50, 1, 0);
    updateRoomDetails(4104, 30, 0, 0);

    string instructor, password;
    cout << "Enter Username: ";
    cin >> instructor;
    cout << "Enter Password: ";
    cin >> password;
    
    if (password == instructor) // SImple Password Scheme
    {
        // Menu driven program for Classroom Booking System
        while (1)
        {
            int choice, choice2, room, time, capacity, effective_date;
            bool projector, ac, conti = 1;
            char contis, login;
            pair<int,int> date;
            string course, day;

            
        
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
            cout << "* Currently Active for dates 01/01/2023 - 31/03/2023";
            cout <<endl;
            cout <<endl;
            cout<<"1.Room Schedule"<<endl;
            cout<<"2.Book Room"<<endl;
            cout<<"3.Cancel Booking"<<endl;
            cout<<"4.Enter Room Details"<<endl;
            cout<<"5.Display Room Details"<<endl;
            cout<<"6.Logout "<<endl;
            cout<<"7.Exit "<<endl;
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
                if (date.second > 3) cout << "System currently Active for dates 01/01/2023 - 31/03/2023";
                else if ((date.second == 3) && (date.first >1)) cout << "System currently Active for dates 31/01/2023 - 01/03/2023";
                else printRoomSchedule(room, date);
                break;
            case 2:
                cout<<"1.One time Room Booking"<<endl;
                cout<<"2.Reccuring Room Booking"<<endl;
                cout<<"Enter your choice : ";
                cin >> choice2;
                switch(choice2)
                {
                    case 1:
                        cout<<"Enter Room Number: ";
                        cin >> room;
                        cout <<"Enter Date (dd/mm): ";
                        cin >> date.first;
                        cin >> date.second;
                        if (date.second > 3) cout << "System currently Active for dates 01/01/2023 - 31/03/2023";
                        else
                        {
                            cout<<"Enter Time Slot: ";
                            cin >> time;
                            cout <<"Enter Course: ";
                            cin >> course;
                            // cout <<"Enter Course Instructor: ";
                            // cin >> instructor;
                            bookRoom(room, date, time, course, instructor);
                        }
                        break;
                    case 2:
                        cout <<"Enter Course: ";
                        cin >> course;
                        // cout <<"Enter Course Instructor: ";
                        // cin >> instructor;
                        cout<<"Enter Room Number: ";
                        cin >> room;
                        cout <<"Enter Today's Date (dd/mm): ";
                        cin >> date.first;
                        cin >> date.second;
                        if (date.second == 1) effective_date = date.first;
                        else if (date.second == 2) effective_date = 31+ date.first;
                        else if (date.second == 3) effective_date = 31+ 28+ date.first;
                        while(conti)
                        {
                            cout << "Enter Day: (Mon/TUe/Wed/Thu/Fri/Sat/Sun): ";
                            cin >> day;
                            cout<<"Enter Time Slot: ";
                            cin >> time;
                            if (day == "Mon") bookRecurrHelper(2, effective_date, room, time, course, instructor);
                            else if (day == "Tue") bookRecurrHelper(3, effective_date, room, time, course, instructor);
                            else if (day == "Wed") bookRecurrHelper(4, effective_date, room, time, course, instructor);
                            else if (day == "Thu") bookRecurrHelper(5, effective_date, room, time, course, instructor);
                            else if (day == "Fri") bookRecurrHelper(6, effective_date, room, time, course, instructor);
                            else if (day == "Sat") bookRecurrHelper(0, effective_date, room, time, course, instructor);
                            else if (day == "Sun") bookRecurrHelper(1, effective_date, room, time, course, instructor);
                            cout << "Do you want to continue? (y/n)";
                            cin >> contis;
                            conti = (contis == 'y') ? 1 : 0;
                        } 
                }
                break;
            case 3:
                cout<<"1.One time Booking Cancellation"<<endl;
                cout<<"2.Reccuring Booking Cancellation"<<endl;
                cout<<"Enter your choice : ";
                cin >> choice2;
                switch(choice2)
                {
                    case 1:
                        cout<<"Enter Room Number: ";
                        cin >> room;
                        cout <<"Enter Date (dd/mm): ";
                        cin >> date.first;
                        cin >> date.second;
                        cout<<"Enter Time Slot: ";
                        cin >> time;
                        cancelBooking(room, date, time, instructor);
                        break;
                    case 2:
                        cout<<"Enter Room Number: ";
                        cin >> room;
                        cout <<"Enter Today's Date (dd/mm): ";
                        cin >> date.first;
                        cin >> date.second;
                        if (date.second == 1) effective_date = date.first;
                        else if (date.second == 2) effective_date = 31+ date.first;
                        else if (date.second == 3) effective_date = 31+ 28+ date.first;
                        while(conti)
                        {
                            cout << "Enter Day: (Mon/Tue/Wed/Thu/Fri/Sat/Sun): ";
                            cin >> day;
                            cout<<"Enter Time Slot: ";
                            cin >> time;
                            if (day == "Mon") cancelRecurrHelper(2, effective_date, room, time, instructor);
                            else if (day == "Tue") cancelRecurrHelper(3, effective_date, room, time, instructor);
                            else if (day == "Wed") cancelRecurrHelper(4, effective_date, room, time, instructor);
                            else if (day == "Thu") cancelRecurrHelper(5, effective_date, room, time, instructor);
                            else if (day == "Fri") cancelRecurrHelper(6, effective_date, room, time, instructor);
                            else if (day == "Sat") cancelRecurrHelper(0, effective_date, room, time, instructor);
                            else if (day == "Sun") cancelRecurrHelper(1, effective_date, room, time, instructor);
                            cout << "Do you want to continue? (y/n)";
                            cin >> contis;
                            conti = (contis == 'y') ? 1 : 0;
                        }
                }
                
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
                cout << "Do you want to login again? (y/n)";
                cin >> login;
                if (login == 'y')
                {   
                    cout << "Enter Username: ";
                    cin >> instructor;
                    cout << "Enter Password: ";
                    cin >> password;
                }
                else if (login == 'n')
                {
                    cout<<"Exiting..."<<endl;
                    exit(1);
                }
                break;
            case 7:
                cout<<"Exiting..."<<endl;
                exit(1);
                break;  
            default:
                cout<<"Wrong choice"<<endl;
            }
        }
    }
    return 0;
}