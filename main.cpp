#include <C:/MinGW/include/DynRPG/DynRPG.h>
#include <windows.h>
#include <stdio.h>

typedef int (__cdecl *MYPROC)(char*);
typedef int (__cdecl *MYPROC2)(int ,char*, int);
HINSTANCE hinstLib;
MYPROC ProcAdd;
MYPROC2 ProcAdd2;
int sock;
int count;
//int mp_id;
//RPG::Character* ev;

void insertIntoCString(int pos, char* dest, char* src){
    for(int i = 0; i < strlen(src);i++){
        dest[i+pos] = src[i];
    }
}

// Handler called on startup
bool onStartup(char *pluginName) {
    //RPG::Character* ev = NULL;
    //mp_id = 0;
    count = 0;
    //return true;
    BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;
    hinstLib = LoadLibrary(TEXT("net_test.dll"));

    if (hinstLib != NULL)
    {
        ProcAdd = (MYPROC) GetProcAddress(hinstLib, "a_net_setup");
        ProcAdd2 = (MYPROC2) GetProcAddress(hinstLib, "a_net_send");

        // If the function address is valid, call the function.

        if (NULL != ProcAdd)
        {
            sock = (ProcAdd) ((char*)"init");
        }
        // Free the DLL module.
        (ProcAdd2) (sock, (char*)"bruh test", 4);
        fFreeResult = FreeLibrary(hinstLib);
        return true;
    }

}
bool onDrawEvent(RPG::Character *character, bool isHero){
    if(isHero){
            if(character != NULL){

            }
    }
    return true;
}
void onFrame(RPG::Scene scene){
    if(scene == RPG::SCENE_MAP){//make sure im not tryina move any heroes whilst not map time.

            //if(ev == NULL){
                /*int num; //the failed attempts to spawn in events instead of illusion of event
                for(int i = 1; i < 256; i++){
                    if(RPG::map->events[i] == NULL){
                        num = i;
                        break;
                    }
                }
                ev = new RPG::Character();
                char buf[3];
                ev->x = RPG::hero->x;
                ev->y = RPG::hero->y;
                ev->id = num;
                ev->enabled = true;
                buf[0] = 0;//RPG::map->events.get(num);
                buf[1] = ev->id;
                buf[2] = ev->enabled;
                buf[3] = ev->mapId;
                buf[4] = ev->x;
                buf[5] = ev->y;
                buf[6] = 'e';

                (ProcAdd2) (sock, buf, 7);*/
            //}


        //RPG::NamedCatalogPtr<RPG::Event*> ev = RPG::map->events;
        //ev.get(0)->x = 3;

        //RPG::system->map
        //if(RPG::map->events[RPG::hero->id] == NULL){
                count++;
                if(count%60 == 1){ //the system isnt designed for so many packets sent
                    char buf[7];
                    buf[0] = 0;//RPG::map->events.get(num);
                    buf[1] = 2;
                    buf[2] = RPG::hero->mapId/256; //here is map id, despite this not being its intended use, it works
                    buf[3] = RPG::hero->mapId%256;
                    (ProcAdd2) (sock, buf, 4);
                    //int size = RPG::hero->charsetFilename.s_str().length();
                    //std::string bruh = "asdasdf";
                    char buf2[4];
                    buf2[0] = 0;
                    buf2[1] = 0;
                    buf2[2] = RPG::hero->charsetId/256;
                    buf2[3] = RPG::hero->charsetId%256;

                    //for(int i = 0; i < RPG::hero->charsetFilename.length(); i++){
                        //buf2[i+2] = [i];
                        //buf2[i+2] = RPG::hero->charsetFilename.s_str()[i];
                    //}
                    (ProcAdd2) (sock, buf2, 4);
                    /*char buf[64];
                    buf[0] = RPG::hero->id%256;
                    buf[1] = RPG::hero->id/256;
                    //character->x++;
                   /* buf[0] = 0;
                    buf[1] = 1;
                    buf[2] = character->x / 256;
                    buf[3] = character->x % 256;
                    buf[4] = character->y / 256;
                    buf[5] = character->y % 256;
                    */
                    /*buf[0] = 'c';
                    buf[1] = 'u';
                    buf[2] = 'm';
                    buf[3] = 'l';
                    buf[4] = 'o';
                    buf[5] = 'r';
                    buf[6] = 'd';*/
                    //(ProcAdd2) (sock, buf, 2);*/

                }

        //->x++;
        //RPG::hero->x++;
    }
}


