#include<bits/stdc++.h>
#include "CreateAndDestroy.h" // include CreateAndDestroy class definition
using namespace std;

// constructor
CreateAndDestroy::CreateAndDestroy( int ID, string messageString )
{
    objectID = ID; // set object's ID number
    message = messageString; // set object's descriptive message

    cout << "Object " << objectID << " constructor runs "
         << message << endl;
} // end CreateAndDestroy constructor

// destructor
CreateAndDestroy::~CreateAndDestroy()
{
    // output newline for certain objects; helps readability
    cout << ( objectID == 1 || objectID == 6 ? "\n" : "" );

    cout << "Object " << objectID << " destructor runs "
         << message << endl;
} // 