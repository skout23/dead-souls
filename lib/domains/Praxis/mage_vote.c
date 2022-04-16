#include <lib.h>
#include <voting.h>
#include <daemons.h>

inherit "/domains/town/room/voters";

void create() {
    ::create();
    SetProperty("light", 1);
    SetProperty("no castle", 1);
    SetProperty("indoors", 1);
    SetShort( "Voting hall of the mages");
    SetLong( (: this_object(), "new_long" :));
    SetItems(
            (["list" : "During election time, it lists all candidates."]) );
    SetExits( 
            (["west" : "/domains/Praxis/mage_hall"]) );
}

string new_long() {
    if(VOTING_D->election_day()) 
        return "This is the room where Mages can put in their bid for office. "
            "If you wish to run for office, just type in the command "
            "'enter race' and you will be added to the list.  A list of candidates "
            "is posted on the wall.  Type 'list candidates' to read it.";
    else return "This is the voting chamber of the Hall of Mages.  "
        "Mages will gather here for the next election: "+VOTING_D->query_vote_date()+".";
}
void init(){
    ::init();
}
