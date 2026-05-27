#include <iostream>
#include <random>
#include <cmath>
#include <windows.h>
#include <string>

using namespace std;
random_device dev;
mt19937 rng(dev());
uniform_int_distribution<uint32_t> uint_dist15(1, 15);
uniform_int_distribution<uint32_t> uint_dist32767(0, 32767);
int damage, spell, turn = 1, luckdmgrate = 2147483647, luckhitrate = 10, hatedmgrate = 10, atkth16 = 90, repeat = 0;
double random, hdrng, mdrng, ldrng;
char p1, p2;
void genrngs() {
    random = (double)uint_dist32767(rng) * 100 / 32767;
    ldrng = (double)uint_dist32767(rng) / 32767 / 5 + 0.6;
    mdrng = (double)uint_dist32767(rng) / 32767 / 5 + 0.9;
    hdrng = (double)uint_dist32767(rng) / 32767 / 5 + 1.2;
}
class fighter {
public:
    int hp = 1000, atk = 100, def = 30, spd = 20, mana = 100, special = 0, special2 = 0, phase = 1, noheal = 0, poison = 0, rskip = 0, karma = 0, dodged = 0,
        silenced = 0, reversed = 0, tempmana = 0, tempspd = 0;
    string name, specialn, special2n;
    fighter(string n, string s1, string s2) {
        name = n;
        specialn = s1;
        special2n = s2;
    }
    friend ostream& operator<<(ostream& os, const fighter& x);
};
fighter a("f r o r g", "LUCK", " A N G E R Y ! ! !"), b("TODD", "HATE", "FEAR..."), c("Player", "???", "CORRUPTION"), d("Sakuya", "Time Gauge", "null"), e("Bette Noire", "HATE", "FEAR...");
//Fighter 1
void reversecard(int& x, fighter& b);
void lottery(fighter& b);
void thirst(fighter& b);
void bslap(fighter& b);
void barf(fighter& b);
void misfortune(fighter& b);
void wakeupslap(fighter& b);
void tornado(fighter& b);
void rain(int& x, fighter& b);
void slice(fighter& b);
void bababooey(fighter& b);
void boing(int& x, fighter& b);
void aneurysm(fighter& b);
void ghost(int& x, fighter& b);
void oneshot(fighter& b);
void bludgeon(fighter& b);
void frogstuffs(fighter& b);
void shutup(int& x, fighter& b);
void diediediedie(fighter& b);
void fin(fighter& b);
//Fighter 2
void multislash(fighter& a);
void sharpprec(fighter& a);
void wound(fighter& a);
void illusion(fighter& a);
void vampwatch(fighter& a);
void detunleashed(fighter& a);
void pslam(fighter& a);
void kheal();
void summonknives(fighter& a);
void lunadial(int& x);
void knifeslash(fighter& a);
void ro_tat_e(fighter& a);
void karmabeach(fighter& a);
void notmydna(int& x, fighter& a);
void backstab(fighter& a);
//Fighter 3
void faketp(fighter& tg);
void darkblast(fighter& tg);
void creepvine(int& x, fighter& tg);
void multiblast(fighter& tg);
void ghosttoss(fighter& tg);
void realknife(fighter& tg);
void srsproblem(fighter& tg);
void fkoff(int& x, fighter& tg);
void wannaknow(fighter& tg);
void codesteal(int& x, char& y, fighter& tg);
void boring(fighter& tg);
void actdelete(int& x);
//Fighter 4
void illsign(fighter& tg);
void slvsign(fighter& tg);
void eternalmek(fighter& tg);
void lumricochet(fighter& tg);
void imagtime(fighter& tg);
void fantakiller(fighter& tg);
void soulsculp(fighter& tg);
void cricochet(fighter& tg);
void jackdababy(fighter& tg);
void lastresort(int& x, fighter& tg);
void sakworld(int& x, fighter& tg);
void statsteal(fighter& tg);
void lunadialII(int& x);
void cringeassault(fighter& tg);
void pushment(int& x, fighter& tg);
//Shared
void swapAll(fighter& a, fighter& b);
void skipturn(fighter& x);
void skipturnII(fighter& x);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

ostream& operator<<(ostream& os, const fighter& x) {
    os << x.name;
    if (x.name.length() < 8) os << "\t";
    os << "\t[";
    if (x.karma > 0) {
        SetConsoleTextAttribute(hConsole, 13);
        os << x.hp << " KR, ";
        SetConsoleTextAttribute(hConsole, turn % 2 * 2 + 10);
    }
    else os << x.hp << " HP, ";
    os << x.atk << " ATK, " << x.def << " DEF, " << x.spd << " SPD, " << x.mana << " MP]";
    if (x.special > 0) os << " === " << x.special << "% " << x.specialn;
    if (x.phase > 1) os << " - " << x.special2 << "% " << x.special2n;
    SetConsoleTextAttribute(hConsole, 7);
    return os;
}
int main()
{
    int raining = 0, rain2 = 0, rain3 = 0, gbd = 0, dna = 0, skcounter = 0, codestealvar = 0, codesteallength = 0; char cstg;
    c.def = 25; d.hp = 2500;
    cout << "SELECT PLAYERS\n Options: " << a.name << " [a], " << b.name << " [b], " << c.name << " [c], " << d.name << " [d], " << e.name << " [e]\nPLAYER 1: ";
    cin >> p1;
    fighter& home = (p1 == 'a') ? a : ((p1 == 'b') ? b : ((p1 == 'c') ? c : ((p1 == 'd') ? d : e)));
    cout << "PLAYER 2: ";
    cin >> p2;
    if (p1 == p2) {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "really.";
        exit(EXIT_FAILURE);
    }
    fighter& guest = (p2 == 'a') ? a : ((p2 == 'b') ? b : ((p2 == 'c') ? c : ((p2 == 'd') ? d : e)));
    cout << "Game START!\n";
    while (home.hp > 0 && guest.hp > 0) {
        genrngs();
        c.karma = 0;
        if (home.karma > 0) {
            home.hp -= 10;
            home.karma--;
        }
        if (guest.karma > 0) {
            guest.hp -= 10;
            guest.karma--;
        }
        SetConsoleTextAttribute(hConsole, 10);
        cout << home;
        SetConsoleTextAttribute(hConsole, 14);
        cout << "\n\tvs.";
        SetConsoleTextAttribute(hConsole, 15);
        if (raining > 0) cout << "\t---RAINING---";
        if (rain2 > 0) {
            SetConsoleTextAttribute(hConsole, 5);
            cout << "\t---CORRUPTED RAIN---";
        }
        if (rain3 > 0) {
            SetConsoleTextAttribute(hConsole, 3);
            cout << "\t---REGRETS---";
        }
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\n" << guest << "\n";
        if (turn % 2 == 1) {
            //P1's turn
            genrngs();
            if (repeat == 0) {
                //Influence setups for p1's attacks
                if (guest.dodged > 0) {
                    guest.tempspd = guest.spd;
                    guest.spd = 1000;
                }
                if (guest.silenced > 0) {
                    home.tempmana = home.mana;
                    home.mana = 0;
                }
            }
            if (codestealvar == 999) {
                random = uint_dist15(rng);
                codestealvar = random;
                codesteallength = 5;
                SetConsoleTextAttribute(hConsole, 9);
                cout << c.name << " deletes a random spell from ";
                if (p1 == 'c') cout << guest.name << "! The selected spell is " << codestealvar << "!\n";
                else cout << home.name << "! The selected spell is " << codestealvar << "!\n";
                if ((p1 == 'c' || p2 == 'c') && spell > 12) {
                    cout << "Uh oh! " << c.name << " doesn't have that many spells! That's a shame.";
                    codestealvar = 0;
                    codesteallength = 0;
                }
                SetConsoleTextAttribute(hConsole, 7);
            }
            if (codesteallength > 0) {
                codesteallength--;
            }
            if (dna == 1) {
                random = uint_dist15(rng);
                spell = random;
                SetConsoleTextAttribute(hConsole, 9);
                cout << b.name << " steals a random spell from ";
                if (p1 == 'b') cout << guest.name << "! The selected spell is " << spell << "!\n";
                else cout << home.name << "! The selected spell is " << spell << "!\n";
                if ((p1 == 'c' || p2 == 'c') && spell > 12) {
                    cout << "Uh oh! " << c.name << " doesn't have that many spells! That's a shame.";
                    spell = 0;
                }
                swapAll(home, guest);
                swap(home.name, guest.name);
            }
            if (turn % 2 == 1) {
                if (home.phase == 1) {
                    cout << home.name << " uses: ";
                    cin >> spell;
                }
                else {
                    cout << home.name;
                    SetConsoleTextAttribute(hConsole, 6);
                    cout << " [PHASE II] ";
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << "uses: ";
                    cin >> spell;
                }
                if (codestealvar != 0 && codesteallength > 0 && spell == codestealvar && p1 == cstg) {
                    cout << "Uh oh! " << home.name << " cannot use that spell yet!\n";
                    spell = 0;
                }
                switch (p1) {
                case 'a':
                    switch (spell) {
                    case 1:
                        reversecard(home.reversed, guest);
                        break;
                    case 2:
                        lottery(guest);
                        break;
                    case 3:
                        thirst(guest);
                        break;
                    case 4:
                        bslap(guest);
                        break;
                    case 5:
                        barf(guest);
                        break;
                    case 6:
                        misfortune(guest);
                        break;
                    case 7:
                        wakeupslap(guest);
                        break;
                    case 8:
                        tornado(guest);
                        break;
                    case 9:
                        rain(raining, guest);
                        break;
                    case 10:
                        slice(guest);
                        break;
                    case 11:
                        bababooey(guest);
                        break;
                    case 12:
                        boing(guest.rskip, guest);
                        break;
                    case 13:
                        aneurysm(guest);
                        break;
                    case 14:
                        ghost(gbd, guest);
                        break;
                    case 15:
                        oneshot(guest);
                        break;
                    case 16:
                        bludgeon(guest);
                        break;
                    case 17:
                        frogstuffs(guest);
                        break;
                    case 18:
                        shutup(home.silenced, guest);
                        break;
                    case 19:
                        diediediedie(guest);
                        break;
                    case 20:
                        fin(guest);
                        break;
                    default:
                        if (home.phase == 1) skipturn(home);
                        else skipturnII(home);
                    }
                    break;
                case 'b':
                    switch (spell) {
                    case 1:
                        multislash(guest);
                        break;
                    case 2:
                        sharpprec(guest);
                        break;
                    case 3:
                        wound(guest);
                        break;
                    case 4:
                        illusion(guest);
                        break;
                    case 5:
                        vampwatch(guest);
                        break;
                    case 6:
                        detunleashed(guest);
                        break;
                    case 7:
                        pslam(guest);
                        break;
                    case 8:
                        kheal();
                        break;
                    case 9:
                        summonknives(guest);
                        break;
                    case 10:
                        lunadial(home.dodged);
                        break;
                    case 11:
                        knifeslash(guest);
                        break;
                    case 12:
                        ro_tat_e(guest);
                        break;
                    case 13:
                        karmabeach(guest);
                        break;
                    case 14:
                        notmydna(dna, guest);
                        break;
                    case 15:
                        backstab(guest);
                        break;
                    default:
                        if (home.phase == 1) skipturn(home);
                        else skipturnII(home);
                    }
                    break;
                case 'c':
                    switch (spell) {
                    case 1:
                        faketp(guest);
                        break;
                    case 2:
                        darkblast(guest);
                        break;
                    case 3:
                        creepvine(guest.rskip, guest);
                        break;
                    case 4:
                        multiblast(guest);
                        break;
                    case 5:
                        ghosttoss(guest);
                        break;
                    case 6:
                        realknife(guest);
                        break;
                    case 7:
                        srsproblem(guest);
                        break;
                    case 8:
                        fkoff(rain2, guest);
                        break;
                    case 9:
                        wannaknow(guest);
                        break;
                    case 10:
                        codesteal(codestealvar, cstg, guest);
                        break;
                    case 11:
                        boring(guest);
                        break;
                    case 12:
                        actdelete(home.dodged);
                        break;
                    default:
                        if (home.phase == 1) skipturn(home);
                        else skipturnII(home);
                    }
                    break;
                case 'd':
                    switch (spell) {
                    case 1:
                        illsign(guest);
                        break;
                    case 2:
                        slvsign(guest);
                        break;
                    case 3:
                        eternalmek(guest);
                        break;
                    case 4:
                        lumricochet(guest);
                        break;
                    case 5:
                        imagtime(guest);
                        break;
                    case 6:
                        fantakiller(guest);
                        break;
                    case 7:
                        soulsculp(guest);
                        break;
                    case 8:
                        cricochet(guest);
                        break;
                    case 9:
                        jackdababy(guest);
                        break;
                    case 10:
                        lastresort(skcounter, guest);
                        break;
                    case 11:
                        sakworld(guest.rskip, guest);
                        break;
                    case 12:
                        statsteal(guest);
                        break;
                    case 13:
                        lunadialII(home.dodged);
                        break;
                    case 14:
                        cringeassault(guest);
                        break;
                    case 15:
                        pushment(rain3, guest);
                        break;
                    default:
                        skipturn(home);
                    }
                    break;
                }
                if (dna == 1) {
                    swapAll(home, guest);
                    swap(home.name, guest.name);
                    SetConsoleTextAttribute(hConsole, 7);
                    dna = 0;
                }
                if (guest.rskip > 0) {
                    guest.rskip--;
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << guest.name << " cannot use a spell yet!\n";
                    SetConsoleTextAttribute(hConsole, 7);
                    turn++;
                }
            }
            if (repeat == 0) {
                if (guest.dodged > 0) {
                    guest.spd = guest.tempspd;
                    if (p2 == 'b') cout << guest.name << " uses their watch to dodge " << home.name << "'s attack!\n";
                    else if (p2 == 'c')cout << guest.name << " uses their console to delete " << home.name << "'s attack!\n";
                    guest.dodged--;
                }
            }   // w a l t e r
            else repeat = 0;
        }
        else {
            //P2's turn
            genrngs();
            if (repeat == 0) {
                //Influence setups for p2's attacks
                if (home.dodged > 0) {
                    home.tempspd = home.spd;
                    home.spd = 1000;
                }
                if (home.silenced > 0) {
                    guest.tempmana = guest.mana;
                    guest.mana = 0;
                }
            }
            else repeat = 0;
            if (gbd == 1) {
                random = uint_dist15(rng);
                spell = random;
                cout << guest.name << " is forced to use a random spell! The ghost selects spell " << spell << "!\n";
                if (codestealvar != 0 && codesteallength > 0 && spell == codestealvar && p2 == cstg) {
                    cout << "Uh oh! " << guest.name << " cannot use that spell yet!\n";
                    spell = 0;
                }
                gbd = 0;
            }
            if (turn % 2 == 0) {
                if (guest.phase == 1) {
                    cout << guest.name << " uses: ";
                    cin >> spell;
                }
                else {
                    cout << guest.name;
                    SetConsoleTextAttribute(hConsole, 6);
                    cout << " [PHASE II] ";
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << "uses: ";
                    cin >> spell;
                }
                if (codestealvar != 0 && codesteallength > 0 && spell == codestealvar && p2 != 'c') {
                    cout << "Uh oh! " << guest.name << " cannot use that spell yet!\n";
                    turn--; repeat = 1;
                }
                switch (p2) {
                case 'a':
                    switch (spell) {
                    case 1:
                        reversecard(home.reversed, home);
                        break;
                    case 2:
                        lottery(home);
                        break;
                    case 3:
                        thirst(home);
                        break;
                    case 4:
                        bslap(home);
                        break;
                    case 5:
                        barf(home);
                        break;
                    case 6:
                        misfortune(home);
                        break;
                    case 7:
                        wakeupslap(home);
                        break;
                    case 8:
                        tornado(home);
                        break;
                    case 9:
                        rain(raining, home);
                        break;
                    case 10:
                        slice(home);
                        break;
                    case 11:
                        bababooey(home);
                        break;
                    case 12:
                        boing(home.rskip, home);
                        break;
                    case 13:
                        aneurysm(home);
                        break;
                    case 14:
                        ghost(gbd, home);
                        break;
                    case 15:
                        oneshot(home);
                        break;
                    case 16:
                        bludgeon(home);
                        break;
                    case 17:
                        frogstuffs(home);
                        break;
                    case 18:
                        shutup(guest.silenced, home);
                        break;
                    case 19:
                        diediediedie(home);
                        break;
                    case 20:
                        fin(home);
                        break;
                    default:
                        if (guest.phase == 1) skipturn(guest);
                        else skipturnII(guest);
                    }
                    break;
                case 'b':
                    switch (spell) {
                    case 1:
                        multislash(home);
                        break;
                    case 2:
                        sharpprec(home);
                        break;
                    case 3:
                        wound(home);
                        break;
                    case 4:
                        illusion(home);
                        break;
                    case 5:
                        vampwatch(home);
                        break;
                    case 6:
                        detunleashed(home);
                        break;
                    case 7:
                        pslam(home);
                        break;
                    case 8:
                        kheal();
                        break;
                    case 9:
                        summonknives(home);
                        break;
                    case 10:
                        lunadial(guest.dodged);
                        break;
                    case 11:
                        knifeslash(home);
                        break;
                    case 12:
                        ro_tat_e(home);
                        break;
                    case 13:
                        karmabeach(home);
                        break;
                    case 14:
                        notmydna(dna, home);
                        break;
                    case 15:
                        backstab(home);
                        break;
                    default:
                        if (guest.phase == 1) skipturn(guest);
                        else skipturnII(guest);
                    }
                    break;
                case 'c':
                    switch (spell) {
                    case 1:
                        faketp(home);
                        break;
                    case 2:
                        darkblast(home);
                        break;
                    case 3:
                        creepvine(home.rskip, home);
                        break;
                    case 4:
                        multiblast(home);
                        break;
                    case 5:
                        ghosttoss(home);
                        break;
                    case 6:
                        realknife(home);
                        break;
                    case 7:
                        srsproblem(home);
                        break;
                    case 8:
                        fkoff(rain2, home);
                        break;
                    case 9:
                        wannaknow(home);
                        break;
                    case 10:
                        codesteal(codestealvar, cstg, home);
                        break;
                    case 11:
                        boring(home);
                        break;
                    case 12:
                        actdelete(guest.dodged);
                        break;
                    default:
                        if (guest.phase == 1) skipturn(guest);
                        else skipturnII(guest);
                    }
                    break;
                case 'd':
                    switch (spell) {
                    case 1:
                        illsign(home);
                        break;
                    case 2:
                        slvsign(home);
                        break;
                    case 3:
                        eternalmek(home);
                        break;
                    case 4:
                        lumricochet(home);
                        break;
                    case 5:
                        imagtime(home);
                        break;
                    case 6:
                        fantakiller(home);
                        break;
                    case 7:
                        soulsculp(home);
                        break;
                    case 8:
                        cricochet(home);
                        break;
                    case 9:
                        jackdababy(home);
                        break;
                    case 10:
                        lastresort(skcounter, home);
                        break;
                    case 11:
                        sakworld(home.rskip, home);
                        break;
                    case 12:
                        statsteal(home);
                        break;
                    case 13:
                        lunadialII(guest.dodged);
                        break;
                    case 14:
                        cringeassault(home);
                        break;
                    case 15:
                        pushment(rain3, home);
                        break;
                    default:
                        skipturn(guest);
                    }
                    break;
                }
                if (home.rskip > 0) {
                    home.rskip--;
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << home.name << " cannot use a spell yet!\n";
                    SetConsoleTextAttribute(hConsole, 7);
                    turn++;
                }       //NO Gs HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            }
            if (repeat == 0) {
                //Dodge / reverse checks for p2's attacks
                if (home.dodged > 0) {
                    home.spd = home.tempspd;
                    SetConsoleTextAttribute(hConsole, 9);
                    if (p1 == 'b') cout << home.name << " uses their watch to dodge " << home.name << "'s attack!\n";
                    else if (p1 == 'c') cout << home.name << " uses their console to delete " << home.name << "'s attack!\n";
                    SetConsoleTextAttribute(hConsole, 7);
                    home.dodged--;
                }
                if (home.reversed > 0) {
                    swapAll(home, guest);
                    SetConsoleTextAttribute(hConsole, 9);
                    cout << guest.name << "'s spell was reversed! Every effect was applied to them instead!\n";
                    SetConsoleTextAttribute(hConsole, 7);
                    home.reversed--;
                }
                if (home.silenced > 0) {
                    guest.mana = guest.tempmana;
                    SetConsoleTextAttribute(hConsole, 9);
                    cout << guest.name << " is no longer silenced!\n";
                    SetConsoleTextAttribute(hConsole, 7);
                    home.silenced--;
                }
                home.mana += 5; guest.mana += 5;
                home.special2++; guest.special2 += 5;
                //Full round actions
                if (raining > 0) {
                    int hpboost, hploss, manaboost, atkloss;
                    manaboost = 15; hpboost = 30; hploss = 10; atkloss = 5;
                    if (a.noheal > 0) {
                        SetConsoleTextAttribute(hConsole, 4);
                        cout << a.name << " is unable to heal!\n";
                        SetConsoleTextAttribute(hConsole, 7);
                        hpboost = 0;
                        a.noheal--;
                    }
                    SetConsoleTextAttribute(hConsole, 14);
                    cout << "The bri'ish rain shows its effects!\n";
                    SetConsoleTextAttribute(hConsole, 2);
                    cout << a.name << " gains " << manaboost << " mana and " << hpboost << " HP!\n";
                    SetConsoleTextAttribute(hConsole, 4);
                    if (p1 == 'a') {
                        cout << guest.name << " loses " << hploss << " HP and " << atkloss << " ATK!\n";
                        guest.hp -= hploss;
                        if (atkloss > guest.atk) guest.atk = 0;
                        else guest.atk -= atkloss;
                    }
                    else {
                        cout << home.name << " loses " << hploss << " HP and " << atkloss << " ATK!\n";
                        home.hp -= hploss;
                        if (atkloss > home.atk) home.atk = 0;
                        else home.atk -= atkloss;
                    }
                    SetConsoleTextAttribute(hConsole, 7);
                    a.mana += manaboost;
                    a.hp += hpboost;
                    raining--;
                }
                if (rain2 > 0) {
                    int hpboost, manaboost, defboost, spdboost;
                    hpboost = 10; manaboost = 10; defboost = 3; spdboost = 1;
                    if (c.noheal > 0) {
                        SetConsoleTextAttribute(hConsole, 4);
                        cout << c.name << " is unable to heal!\n";
                        SetConsoleTextAttribute(hConsole, 7);
                        hpboost = 0;
                        c.noheal--;
                    }
                    SetConsoleTextAttribute(hConsole, 14);
                    cout << "The corrupted rain shows its effects!\n";
                    SetConsoleTextAttribute(hConsole, 2);
                    cout << c.name << " gains " << manaboost << " MP, " << defboost << " DEF, " << spdboost << " SPD and " << hpboost << " HP!\n";
                    SetConsoleTextAttribute(hConsole, 4);
                    if (p1 == 'c') {
                        cout << guest.name << " loses these stats!\n";
                        guest.hp -= hpboost;
                        guest.mana -= manaboost;
                        guest.def -= defboost;
                        guest.spd -= spdboost;
                    }
                    else {
                        cout << home.name << " loses these stats!\n";
                        home.hp -= hpboost;
                        home.mana -= manaboost;
                        home.def -= defboost;
                        home.spd -= spdboost;
                    }
                    SetConsoleTextAttribute(hConsole, 7);
                    c.mana += manaboost;
                    c.hp += hpboost;
                    rain2--;
                }
                if (rain3 > 0) {
                    int hpboost, manaboost, atkboost;
                    hpboost = 40; manaboost = 10; atkboost = 5;
                    SetConsoleTextAttribute(hConsole, 14);
                    cout << "The regrets make ";
                    if (p1 == 'd') cout << guest.name << " suffer!\n";
                    else cout << home.name << " suffer!\n";
                    SetConsoleTextAttribute(hConsole, 4);
                    if (p1 == 'd') {
                        cout << guest.name << " loses " << hpboost << " HP, " << manaboost << " mana and " << atkboost << " ATK!\n";
                        guest.hp -= hpboost;
                        guest.mana -= manaboost;
                        guest.atk -= atkboost;
                    }
                    else {
                        cout << home.name << " loses " << hpboost << " HP, " << manaboost << " mana and " << atkboost << " ATK!\n";
                        home.hp -= hpboost;
                        home.mana -= manaboost;
                        home.atk -= atkboost;
                    }
                    SetConsoleTextAttribute(hConsole, 7);
                    rain3--;
                }
            }
        }
        turn++;
        if (home.atk < 0) home.atk = 0;
        if (guest.atk < 0) guest.atk = 0;
        if (home.def < 0) home.def = 0;
        if (guest.def < 0) guest.def = 0;
        if (home.spd < 0) home.spd = 0;
        if (guest.spd < 0) guest.spd = 0;
        if (home.mana < 0) home.mana = 0;
        if (guest.mana < 0) guest.mana = 0;
        if (home.spd > 100) home.spd = 100;
        if (guest.spd > 100) guest.spd = 100;
        if (home.mana > 200) home.mana = 200;
        if (guest.mana > 200) guest.mana = 200;
        if (home.special < 0) home.special = 0;
        if (guest.special < 0) guest.special = 0;
        if (home.special2 < 0) home.special2 = 0;
        if (guest.special2 < 0) guest.special2 = 0;
        if (home.phase == 1) home.special2 = 0;
        if (guest.phase == 1) guest.special2 = 0;
        //Phase II checks
        if (a.hp < 300 && a.mana < 60 && a.phase == 1) {
            a.phase = 2;
            a.hp = 300;
            a.def = 80;
            a.mana = 90;
            a.special2 = 3;
            SetConsoleTextAttribute(hConsole, 5);
            cout << a.name << " enters PHASE II! They recovered some mana and HP, and their DEF is boosted significantly!\n";
            SetConsoleTextAttribute(hConsole, 7);
        }
        if (b.hp < 300 && b.mana < 60 && b.phase == 1) {
            b.phase = 2;
            b.hp = 300;
            b.atk = 140;
            b.mana = 150;
            b.special2 = 15;
            SetConsoleTextAttribute(hConsole, 5);
            cout << b.name << " enters PHASE II! They recovered some mana and HP, and their ATK is boosted significantly!\n";
            SetConsoleTextAttribute(hConsole, 7);
        }
        if (c.hp < 0 && c.phase == 1) {
            c.phase = 2;
            c.hp = 300;
            c.atk += 20;
            c.def += 20;
            c.mana = 100;
            c.special2 = 15;
            SetConsoleTextAttribute(hConsole, 5);
            cout << c.name << " enters PHASE II! They recovered some mana and HP, and their ATK & DEF are boosted!\n";
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
    SetConsoleTextAttribute(hConsole, 26);
    if (home.hp > 0)
        if (guest.hp > 0)
            if (home.spd > guest.spd) cout << home.name << " wins [SPD]\n";
            else if (guest.spd > home.spd) cout << guest.name << " wins [SPD]\n";
            else cout << "Draw\n";
        else cout << home.name << " wins\n";
    else cout << guest.name << " wins\n";
    return turn / 2 + turn % 2;
}
void swapAll(fighter& a, fighter& b) {
    swap(a.hp, b.hp);
    swap(a.atk, b.atk);
    swap(a.def, b.def);
    swap(a.spd, b.spd);
    swap(a.special, b.special);
    swap(a.special2, b.special2);
    swap(a.rskip, b.rskip);
}
void skipturn(fighter& x) {
    x.mana += 5;
    cout << x.name << " chooses to skip their turn and receive some mana!\n";
}
void skipturnII(fighter& x) {
    x.mana += 5;
    x.special2 += 3;
    cout << x.name << " chooses to skip their turn and receive some mana and special stats!\n";
}
//Fighter 1
void reversecard(int& x, fighter& b) {
    int cost = 25;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        a.mana -= cost;
        x = 1;
        swapAll(a, b);
        cout << "Something terrible is about to happen...\n";
    }
}
void lottery(fighter& b) {
    int cost = 15;
    if (a.special < cost) {
        cout << "Not enough LUCK!\n";
        turn--; repeat = 1;
    }
    else if (random < b.spd - a.special / luckhitrate) {
        cout << a.name << " tries to act, but " << b.name << " acts faster!\n";
        a.special -= cost;
    }
    else {
        cout << a.name << " visits the lottery!\n";
        if (random < 20) {
            damage = 10 * a.atk - b.def;
            if (damage <= 0) {
                cout << a.name << " uses a formidable attack, yet " << b.name << " is able to block it in its entirety, taking 0 damage!\n";
            }
            else {
                b.hp -= damage;
                cout << a.name << " wins the grand prize! " << b.name << " takes " << damage << " damage!\n";
            }
        }
        else if (random < 40) {
            damage = 1.2 * a.special;
            if (damage <= 0) {
                cout << a.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                b.hp -= damage;
                cout << a.name << " wins the second prize! " << b.name << " takes " << damage << " damage!\n";
            }
        }
        else if (random < 60) {
            damage = a.special / 10;
            b.def -= damage;
            cout << a.name << " finds " << b.name << "'s ticket and uses it instead! " << b.name << " loses " << damage << " DEF!\n";
        }
        else if (random < 80) {
            damage = round(a.special / 50);
            a.spd += damage;
            cout << a.name << " steals " << b.name << "'s ticket from right under their nose! " << a.name << " gains " << damage << " SPD!\n";
        }
        else {
            damage = 30;
            a.special -= damage;
            cout << a.name << " spends their money, but wins nothing. " << a.name << " loses " << damage << " LUCK in the process.\n";
        }
        a.special -= cost;
    }
}
void thirst(fighter& b) {
    int cost = 20;
    if (a.special < cost) {
        cout << "Not enough LUCK!\n";
        turn--; repeat = 1;
    }
    else {
        damage = 10;
        b.mana -= damage;
        a.mana += damage;
        cout << a.name << " absorbs " << damage << " mana from " << b.name << "!\n";
        a.special -= cost;
    }
}
void bslap(fighter& b) {
    int cost = 16;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        cout << a.name << " slaps " << b.name << "!\n";
        for (int i = 0; i < 1.01 + a.special / luckdmgrate; i++) {
            genrngs();
            if (random < b.spd - a.special / luckhitrate) {
                cout << a.name << "'s attack missed!\n";
            }
            else {
                damage = round((mdrng/* + (double)a.special / luckdmgrate*/)*a.atk);
                if (damage <= 0) {
                    cout << a.name << "'s attack hits, but deals 0 damage!\n";
                }
                else {
                    b.hp -= damage;
                    cout << b.name << " takes " << damage << " damage!\n";
                }
            }
            Sleep(100);
        }
        a.mana -= cost;
    }
}
void barf(fighter& b) {
    int cost = 15;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        cout << a.name << " did not enjoy their last meal!\n";
        if (random < b.spd - a.special / luckhitrate) {
            cout << a.name << "'s attack missed!\n";
        }
        else {
            damage = round((hdrng/* + (double)a.special / luckdmgrate*/)*a.atk) - b.def;
            if (damage <= 0) {
                cout << a.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                b.hp -= damage;
                cout << a.name << " barfs on " << b.name << ", dealing " << damage << " damage! ";
            }
            damage = 10;
            b.atk -= damage;
            cout << b.name << " loses " << damage << " ATK!\n";
        }
        a.mana -= cost;
    }
}
void misfortune(fighter& b) {
    int cost = 16;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        cout << a.name << " wishes an unfortunate fate to " << b.name << "!\n";
        damage = 5 * a.special - b.def;
        if (damage <= 0) {
            cout << a.name << "'s wish is not heard! " << b.name << " takes 0 damage!\n";
        }
        else {
            b.hp -= damage;
            cout << a.name << "'s wish comes true! " << b.name << " takes " << damage << " damage!\n";
            a.mana -= cost;
        }
        a.special = 0;
    }
}
void wakeupslap(fighter& b) {
    int cost = 15;
    int hitcount = 20;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        cout << a.name << " wakes up " << b.name << "!\n";
        damage = round(0.2 * a.atk) - b.def;
        if (damage <= 0) {
            cout << a.name << "'s attacks deal 0 damage!\n";
        }
        else {
            for (int i = 0; i < 20; i++) {
                genrngs();
                if (random < b.spd - a.special / luckhitrate) hitcount--;
            }
            cout << a.name << "'s attacks hit " << hitcount;
            if (hitcount == 1) cout << " time";
            else cout << " times";
            cout << " and miss " << 20 - hitcount;
            if (hitcount == 19) cout << " time! ";
            else cout << " times! ";
            b.hp -= damage * hitcount;
            cout << b.name << " takes " << damage * hitcount << " damage!\n";
        }
        a.mana -= cost;
    }
}
void tornado(fighter& b) {
    int cost = 40;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        cout << a.name << " launches a furious tornado towards " << b.name << "!\n";
        if (random < b.spd - a.special / luckhitrate) {
            cout << a.name << "'s attack missed!\n";
        }
        else {
            damage = 20;
            b.atk -= damage;
            b.def -= damage;
            b.mana -= damage;
            b.special -= damage;
            cout << b.name << " gets hit by " << a.name << "'s tornado! Their stats are reduced by " << damage << " points!\n";
        }
        a.mana -= cost;
    }
}
void rain(int& x, fighter& b) {
    int cost = 31;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        x = 3;
        cout << a.name << " curses the battlefield with " << x << " rounds of bri'ish rain!\n";
        a.mana -= cost;
    }
}
void slice(fighter& b) {
    int cost = 9;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        cout << a.name << " slices " << b.name << " with their lucky knife!\n";
        if (random < b.spd - a.special / luckhitrate) {
            cout << a.name << "'s attack missed!\n";
        }
        else {
            damage = round((mdrng/* + (double)a.special / luckdmgrate*/)*a.atk) - b.def;
            if (damage <= 0) {
                cout << a.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                b.hp -= damage;
                a.special += damage / 2 + damage % 2;
                cout << a.name << " hits " << b.name << " dealing " << damage << " damage and gaining " << damage / 2 + damage % 2 << " LUCK!\n";
            }
        }
        a.mana -= cost;
    }
}
void bababooey(fighter& b) {
    int cost = 15;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        cout << a.name << " throws a cat at " << b.name << "!\n";
        if (random < 50) {
            cout << a.name << "'s cat wanders off into the universe!\n";
        }
        else {
            genrngs();
            if (random < b.spd - a.special / luckhitrate) {
                cout << a.name << "'s cat nearly hits, but " << b.name << " dodges it in time!\n";
            }
            else {
                damage = round((hdrng/* + (double)a.special / luckdmgrate*/)*a.atk) - b.def;
                if (damage <= 0) {
                    cout << a.name << "'s attack hits, but deals 0 damage!\n";
                }
                else {
                    b.hp -= damage;
                    cout << a.name << "'s cat hits " << b.name << " directly in the face! " << b.name << " takes " << damage << " damage!\n";
                }
                damage = 1;
                b.spd -= damage;
                cout << b.name << " loses " << damage << " SPD!\n";
            }
        }
        a.mana -= cost;
    }
}
void boing(int& x, fighter& b) {
    int cost = 18;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        cout << a.name << " tries to punch " << b.name << " with an extendo grip!\n";
        if (random < b.spd - a.special / luckhitrate) {
            cout << a.name << "'s attack missed!\n";
        }
        else {
            damage = round(ldrng * a.atk) - b.def;
            if (damage <= 0) {
                cout << a.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                b.hp -= damage;
                cout << b.name << " takes " << damage << " damage!\n";
            }
            cout << b.name << " gets shoved very far away!\n";
            x += 2;
        }
        a.mana -= cost;
    }
}
void aneurysm(fighter& b) {
    int cost = 25;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        cout << a.name << " types some random gibberish in the chat!\n";
        if (random < b.spd - a.special / luckhitrate) {
            cout << a.name << "'s attack missed!\n";
        }
        else {
            b.special = b.special2 = 0;
            cout << b.name << " has an aneurysm and loses all their special stats!\n";
        }
        a.mana -= cost;
    }
}
void ghost(int& x, fighter& b) {
    int cost = 10;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < b.spd - a.special / luckhitrate) {
            cout << a.name << "'s attack missed!\n";
        }
        else {
            x = 1;
            cout << a.name << " releases a cheeky ghost that seeks " << b.name << " and ruins their plans!\n";
        }
        a.mana -= cost;
    }
}
void oneshot(fighter& b) {
    int cost = 41;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        cout << a.name << " gets MAD at " << b.name << "!\n";
        if (random < b.spd) {
            cout << a.name << " misses their smack and gets EVEN MORE MAD! Their attack is increased by 10!\n";
            a.atk += 10;
        }
        else {
            damage = round(mdrng * a.atk) - b.def;
            b.hp -= damage;
            a.hp += damage - floor(damage / 10);
            a.atk += floor(damage / 10);
            cout << a.name << " smacks " << b.name << " directly in the butt, dealing " << damage << " emotional damage, stealing their HP & transforming part of it into ATK!\n";
        }
        a.mana -= cost;
    }
}
void bludgeon(fighter& b) {
    int cost = 3;
    if (a.special2 < cost) {
        cout << "Not enough  A N G E R Y ! ! !\n";
        turn--; repeat = 1;
    }
    else if (a.atk > atkth16) {
        cout << a.name << " grabs a nearby stick and approaches " << b.name << "!\n";
        for (int i = 0; i < 3; i++) {
            genrngs();
            if (random < b.spd - a.special / luckhitrate) {
                cout << a.name << "'s attack missed!\n";
            }
            else {
                damage = round((mdrng/* + (double)a.special / luckdmgrate*/)*a.atk);
                if (damage <= 0) {
                    cout << a.name << "'s attack hits, but deals 0 damage!\n";
                }
                else {
                    b.hp -= damage;
                    cout << a.name << " hits " << b.name << " with his stick! " << b.name << " takes " << damage << " damage!\n";
                }
            }
        }
        a.special2 -= cost;
    }
    else cout << a.name << " is not skilled enough to bludgeon " << b.name << "!\n";
}
void frogstuffs(fighter& b) {
    int cost = 2;
    if (a.special2 < cost) {
        cout << "Not enough  A N G E R Y ! ! !\n";
        turn--; repeat = 1;
    }
    else {
        if (random < b.spd - a.special / luckhitrate) {
            cout << a.name << "'s attack missed!\n";
        }
        else {
            cout << a.name << " starts inhaling " << b.name << " as if they were Kirby!\n";
            damage = round((ldrng/* + (double)a.special / luckdmgrate*/)*a.atk) - b.def;
            b.hp -= damage;
            cout << a.name << " eats " << b.name << " and deals " << damage << " damage!\n";
            a.hp += ceil(b.hp / 10);
            a.atk += ceil(b.atk / 10);
            a.def += ceil(b.def / 10);
            a.spd += ceil(b.spd / 10);
            a.mana += ceil(b.mana / 10);
            a.special += ceil(b.special / 10);
            a.special2 += ceil(b.special2 / 10);
        }
        a.special2 -= cost;
    }
}
void shutup(int& x, fighter& b) {
    int cost = 4;
    if (a.special2 < cost) {
        cout << "Not enough  A N G E R Y ! ! !\n";
        turn--; repeat = 1;
    }
    else {
        x = 1;
        cout << a.name << " makes " << b.name << " shut the fuck up! " << b.name << " cannot use mana for the following round!\n";
        a.special2 -= cost;
    }

}
void diediediedie(fighter& b) {
    int cost = 1;
    if (a.special2 < cost) {
        cout << "Not enough  A N G E R Y ! ! !\n";
        turn--; repeat = 1;
    }
    else {
        cout << a.name << " lets out some anger on " << b.name << "!\n";
        for (int i = 0; i < 4; i++) {
            genrngs();
            if (random < b.spd - a.special / luckhitrate) {
                cout << a.name << "'s attack missed!\n";
            }
            else {
                damage = round((0.3/* + (double)a.special / (luckdmgrate * 1.5)*/) * a.atk) - b.def;
                if (damage <= 0) {
                    cout << a.name << "'s attack hits, but deals 0 damage!\n";
                }
                else {
                    b.hp -= damage;
                    cout << a.name << " smacks " << b.name << ", dealing " << damage << " damage!\n";
                }
            }
        }
        a.special2 -= cost;
    }
}
void fin(fighter& b) {
    int cost = 10;
    if (a.special2 < cost) {
        cout << "Not enough  A N G E R Y ! ! !\n";
        turn--; repeat = 1;
    }
    else {
        cout << a.name << " has had it up to HERE with " << b.name << "!\n";
        if (random < b.spd - a.special / luckhitrate) {
            cout << a.name << "'s attack did not reach " << b.name << "'s ears!\n";
        }
        else {
            damage = round(5 * (mdrng)*a.atk) - b.def;
            if (damage <= 0) {
                cout << a.name << "hits with a formidable attack, yet " << b.name << " is able to block it in its entirety, taking 0 damage!\n";
            }
            else {
                b.hp -= damage;
                cout << a.name << " loudly exclaims \"FUCK YOU\" in " << b.name << "'s face, dealing " << damage << " emotional damage!\n";
            }
        }
        a.special2 -= cost;
    }
}
//Fighter 2
void multislash(fighter& a) {
    int cost = 4;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < a.spd - 10) {
            cout << b.name << "'s attack missed!\n";
        }
        else {
            damage = round(ldrng * (b.atk + b.special / hatedmgrate)) - a.def;
            if (damage <= 0) {
                cout << b.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                a.hp -= damage;
                cout << b.name << " stabs " << a.name << " several times with his homing knives! " << a.name << " takes " << damage << " damage!\n";
            }
        }
        b.mana -= cost;
    }
}
void sharpprec(fighter& a) {
    int cost = 3;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < a.spd) {
            cout << b.name << "'s attack missed!\n";
        }
        else {
            damage = round(ldrng * (b.atk + b.special / hatedmgrate)) - a.def;
            if (damage <= 0) {
                cout << b.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                a.hp -= damage;
                cout << b.name << " throws several knives at " << a.name << ", which deal " << damage << " damage!\n";
            }
        }
        b.mana -= cost;
    }
}
void wound(fighter& a) {
    int cost = 15;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < a.spd) {
            cout << b.name << "'s attack misses!\n";
        }
        else {
            damage = round(mdrng * (b.atk + b.special / hatedmgrate)) - a.def;
            if (damage <= 0) {
                cout << b.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                a.hp -= damage;
                cout << b.name << " unleashes a flurry of red slashes at a blinding speed! " << a.name << " takes " << damage << " damage!\n";
            }
        }
        b.mana -= cost;
    }
}
void illusion(fighter& a) {
    int cost = 20;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        damage = round(hdrng * (b.atk + b.special / hatedmgrate)) - a.def;
        if (damage <= 0) {
            cout << b.name << "'s attack hits, but deals 0 damage!\n";
        }
        else {
            a.hp -= damage;
            cout << b.name << " freezes time around " << a.name << " and throws many knives at them! " << a.name << " takes " << damage << " damage!\n";
        }
        b.mana -= cost;
    }
}
void vampwatch(fighter& a) {
    int cost = 17;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < a.spd) {
            cout << b.name << "'s attack misses!\n";
        }
        else {
            damage = round(mdrng * (b.atk + b.special / hatedmgrate)) - a.def;
            if (damage <= 0) {
                cout << b.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                a.hp -= damage;
                b.hp += damage;
                cout << b.name << " throws a pocket watch at " << a.name << "! They take " << damage << " damage and " << b.name << " steals their HP!\n";
            }
        }
        b.mana -= cost;
    }
}
void detunleashed(fighter& a) {
    int cost = 18;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        damage = round(hdrng * (b.atk + b.special / hatedmgrate)) - a.def;
        if (damage <= 0) {
            cout << b.name << "'s attack hits, but deals 0 damage!\n";
        }
        else {
            a.hp -= damage;
            cout << b.name << " welcomes " << a.name << " into their special hell! " << a.name << " takes " << damage << " damage!\n";
        }
        b.mana -= cost;
    }
}
void pslam(fighter& a) {
    int cost = 10;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < a.spd) {
            cout << b.name << "'s attack missed!\n";
        }
        else {
            damage = round(mdrng * (b.atk + b.special / hatedmgrate)) - a.def;
            if (damage <= 0) {
                cout << b.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                a.hp -= damage;
                cout << b.name << " slams " << a.name << " into the ground! " << a.name << " takes " << damage << " damage!\n";
            }
        }
        b.mana -= cost;
    }
}
void kheal() {
    int cost = 25;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        int healpw = 200;
        b.hp += healpw;
        cout << b.name << " heals up " << healpw << " HP using their knife!\n";
        b.mana -= cost;
    }
}
void summonknives(fighter& a) {
    int cost = 20;
    if (b.special2 < cost) {
        cout << "Not enough FEAR...\n";
        turn--; repeat = 1;
    }
    else {
        if (random < a.spd) {
            cout << b.name << "'s attack missed!\n";
        }
        else {
            damage = round(hdrng * (b.atk + b.special / hatedmgrate)) - a.def;
            if (damage <= 0) {
                cout << b.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                a.hp -= damage;
                cout << b.name << " summons hundreds of knives that stab " << a.name << ", dealing " << damage << " damage!\n";
            }
        }
        b.special2 -= cost;
    }
}
void lunadial(int& x) {
    int cost = 15;
    if (b.special2 < cost) {
        cout << "Not enough FEAR...\n";
        turn--; repeat = 1;
    }
    else {
        x = 1;
        SetConsoleTextAttribute(hConsole, 4);
        cout << b.name << " readies their bronze watch!\n";
        SetConsoleTextAttribute(hConsole, 7);
        b.special2 -= cost;
    }
}
void knifeslash(fighter& a) {
    int cost = 25;
    if (b.special2 < cost) {
        cout << "Not enough FEAR...\n";
        turn--; repeat = 1;
    }
    else {
        if (random < a.spd) {
            cout << b.name << "'s attack missed!\n";
        }
        else {
            damage = round(hdrng * (b.atk + b.special / hatedmgrate)) - a.def;
            if (damage <= 0) {
                cout << b.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                a.hp -= damage;
                b.special += damage / 20;
                cout << b.name << " slashes " << a.name << " with thousands of knives, dealing " << damage << " damage and gaining " << damage / 10 << " HATE!\n";
            }
        }
        b.special2 -= cost;
    }
}
void ro_tat_e(fighter& a) {
    int cost = 30;
    int inacc = 50;
    if (b.special2 < cost) {
        cout << "Not enough FEAR...\n";
        turn--; repeat = 1;
    }
    else {
        cout << b.name << " starts RO-TAT-ING!\n";
        for (int i = 0; i < 5; i++) {
            genrngs();
            if (random < a.spd + inacc) {
                cout << b.name << "'s attack missed!\n";
            }
            else {
                damage = round(hdrng * (b.atk + b.special / hatedmgrate)) - a.def;
                if (damage <= 0) {
                    cout << b.name << "'s attack hits, but deals 0 damage!\n";
                }
                else {
                    a.hp -= damage;
                    cout << b.name << " hits " << a.name << " with a knife while RO-TAT-Eing! " << a.name << " takes " << damage << " damage!\n";
                }
            }
        }
        b.special2 -= cost;
    }
}
void karmabeach(fighter& a) {
    int cost = 20;
    if (b.special2 < cost) {
        cout << "Not enough FEAR...\n";
        turn--; repeat = 1;
    }
    else {
        if (random < a.spd) {
            cout << b.name << "'s attack missed!\n";
        }
        else {
            damage = floor(a.hp / 10);
            a.noheal = 5;
            a.karma = floor(damage / 10);
            cout << a.name << " takes " << damage << " karma damage from " << b.name << ", and cannot heal for " << a.noheal << " rounds!\n";
        }
        b.special2 -= cost;
    }
}
void notmydna(int& x, fighter& a) {
    int cost = 15;
    if (b.special2 < cost) {
        cout << "Not enough FEAR...\n";
        turn--; repeat = 1;
    }
    else {
        x = 1;
        cout << b.name << " \"borrows\" " << a.name << "'s DNA without permission!\n";
        b.special2 -= cost;
    }
}
void backstab(fighter& a) {
    int cost = 25;
    if (b.special2 < cost) {
        cout << "Not enough FEAR...\n";
        turn--; repeat = 1;
    }
    else {
        cout << b.name << " sneaks behind " << a.name << "!\n";
        if (random < a.spd - 5) {
            cout << b.name << "'s attack missed!\n";
        }
        else {
            damage = floor(a.hp * 3 / 20);
            a.hp -= damage;
            b.hp += damage;
            cout << b.name << " BACKSTABS " << a.name << ", stealing " << damage << " HP and ";
            damage = floor(a.mana / 10);
            a.mana -= damage;
            b.mana += damage;
            cout << damage << " mana!\n";
        }
        b.special2 -= cost;
    }
}
//Fighter 3
void faketp(fighter& tg) {
    int cost = 6;
    if (c.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < tg.spd) {
            cout << c.name << "'s attack missed!\n";
        }
        else {
            damage = round(mdrng * c.atk) - tg.def;
            if (damage <= 0) {
                cout << c.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                tg.hp -= damage;
                cout << c.name << " slashes " << tg.name << " with a fake teleport, dealing " << damage << " damage!\n";
            }
        }
        c.mana -= cost;
    }
}
void darkblast(fighter& tg) {
    int cost = 6;
    if (c.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < tg.spd) {
            cout << c.name << "'s attack missed!\n";
        }
        else {
            damage = round(mdrng * c.atk) - tg.def;
            if (damage <= 0) {
                cout << c.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                tg.hp -= damage;
                cout << c.name << " hits " << tg.name << " with a dark blaster, dealing " << damage << " damage!\n";
            }
        }
        c.mana -= cost;
    }
}
void creepvine(int& x, fighter& tg) {
    int cost = 18;
    if (c.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < tg.spd) {
            cout << c.name << "'s attack missed!\n";
        }
        else {
            x += 2;
            cout << c.name << " stuns " << tg.name << " with vines for " << x << " rounds!\n";
        }
        c.mana -= cost;
    }
}
void multiblast(fighter& tg) {
    int cost = 14;
    if (c.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < tg.spd) {
            cout << c.name << "'s attack missed!\n";
        }
        else {
            damage = round(hdrng * c.atk) - tg.def;
            if (damage <= 0) {
                cout << c.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                tg.hp -= damage;
                cout << c.name << " blasts " << tg.name << " with 5 blasters, dealing " << damage << " damage!\n";
            }
        }
        c.mana -= cost;
    }
}
void ghosttoss(fighter& tg) {
    int cost = 9;
    if (c.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < tg.spd) {
            cout << c.name << "'s attack missed!\n";
        }
        else {
            damage = round(mdrng * c.atk) - tg.def;
            if (damage <= 0) {
                cout << c.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                tg.hp -= damage;
                cout << c.name << " hits " << tg.name << " with a phantom blade, dealing " << damage << " damage!\n";
                damage = 10;
                c.mana += damage;
                tg.mana -= damage;
                cout << c.name << " steals " << damage << " mana from " << tg.name << "!\n";
            }
        }
        c.mana -= cost;
    }
}
void realknife(fighter& tg) {
    int cost = 3;
    if (c.mana < cost) {
        cout << "Not enough mana! Why are you so BROKE!?\n";
        turn--; repeat = 1;
    }
    else {
        if (random < tg.spd) {
            cout << c.name << "'s attack missed!\n";
        }
        else {
            damage = round(ldrng * c.atk) - tg.def;
            if (damage <= 0) {
                cout << c.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                tg.hp -= damage;
                cout << c.name << " stabs " << tg.name << " with a fake-real knife, dealing " << damage << " damage!\n";
            }
        }
        c.mana -= cost;
    }
}
void srsproblem(fighter& tg) {
    int cost = 13;
    if (c.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < tg.spd) {
            cout << c.name << "'s attack missed!\n";
        }
        else {
            damage = round(hdrng * c.atk) - tg.def;
            if (damage <= 0) {
                cout << c.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                tg.hp -= damage;
                cout << c.name << " spawns a REAL real knife and stabs " << tg.name << " with it, dealing " << damage << " damage!\n";
            }
        }
        c.mana -= cost;
    }
}
void fkoff(int& x, fighter& tg) {
    int cost = 60;
    if (c.mana < cost) {
        cout << "Not enough corruption?\n";
        turn--; repeat = 1;
    }
    else {
        x = 3;
        cout << c.name << " curses " << tg.name << " with " << x << " rounds of corrupted rain!\n";
        c.mana -= cost;
    }
}
void wannaknow(fighter& tg) {
    int cost = 31;
    if (c.special2 < cost) {
        cout << "Not enough corruption?\n";
        turn--; repeat = 1;
    }
    else {
        if (random < tg.spd) {
            cout << c.name << "'s attack missed!\n";
        }
        else {
            damage = round(3 * mdrng * c.atk) - tg.def;
            if (damage <= 0) {
                cout << c.name << "'s attack hits with a formidable attack, but " << tg.name << " is able to block it in its entirety!\n";
            }
            else {
                tg.hp -= damage;
                cout << c.name << " asks " << tg.name << " if they want to know what just happened, but doesn't wait for an answer! He deals " << damage << " damage!\n";
            }
        }
        c.special2 -= cost;
    }
}
void codesteal(int& x, char& y, fighter& tg) {
    int cost = 15;
    if (c.special2 < cost) {
        cout << "Not enough FEAR...\n";
        turn--; repeat = 1;
    }
    else {
        x = 999;
        cout << c.name << " edits " << tg.name << "'s code!\n";
        if (p1 == 'c') y = p2;
        else y = p1;
        c.special2 -= cost;
    }
}
void boring(fighter& tg) {
    int cost = 30;
    if (c.special2 < cost) {
        cout << "Not enough corruption?\n";
        turn--; repeat = 1;
    }
    else {
        damage = c.hp / 10;
        c.hp += damage;
        damage = c.atk / 10;
        c.atk += damage;
        damage = c.def / 10;
        c.def += damage;
        damage = c.mana / 10;
        c.mana += damage;
        damage = c.spd / 10;
        c.spd += damage;
        cout << c.name << " buffs himself by 10% for all his stats!\n";
        c.special2 -= cost;
    }
}
void actdelete(int& x) {
    int cost = 15;
    if (c.special2 < cost) {
        cout << "Not enough corruption?\n";
        turn--; repeat = 1;
    }
    else {
        x = 1;
        SetConsoleTextAttribute(hConsole, 4);
        cout << c.name << " prepares the console!\n";
        SetConsoleTextAttribute(hConsole, 7);
        c.special2 -= cost;
    }
}
//Fighter 4
void illsign(fighter& tg) {
    int cost = 6;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < tg.spd) {
            cout << d.name << "'s attack missed!\n";
        }
        else {
            damage = round(mdrng * d.atk) - tg.def;
            if (damage <= 0) {
                cout << d.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                tg.hp -= damage;
                cout << d.name << " throws 32 knives at " << tg.name << ", dealing " << damage << " damage!\n";
            }
        }
        d.mana -= cost;
    }
}
void slvsign(fighter& tg) {
    int cost = 3;
    if (d.mana < cost) {
        cout << "Not enough mana! Why are you so BROKE!?\n";
        turn--; repeat = 1;
    }
    else {
        if (random < tg.spd) {
            cout << d.name << "'s attack missed!\n";
        }
        else {
            damage = round(ldrng * d.atk) - tg.def;
            if (damage <= 0) {
                cout << d.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                tg.hp -= damage;
                cout << d.name << " launches some bouncy knives towards " << tg.name << ", dealing " << damage << " damage!\n";
            }
        }
        d.mana -= cost;
    }
}
void eternalmek(fighter& tg) {
    int cost = 12;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        cout << d.name << " throws 4 knives towards " << tg.name << "!\n";
        int tdmg = 0;
        for (int i = 0; i < 4; i++) {
            genrngs();
            if (random < tg.spd) {
                cout << d.name << "'s knife missed!\n";
            }
            else {
                damage = round(ldrng * d.atk) - tg.def;
                if (damage <= 0) {
                    cout << d.name << "'s knife hits, but deals 0 damage!\n";
                }
                else {
                    tg.hp -= damage;
                    cout << d.name << "'s knife hits " << tg.name << " for " << damage << " damage!\n";
                    tdmg += damage;
                }
            }
            Sleep(100);
        }
        cout << d.name << " deals a total of " << tdmg << " damage to " << tg.name << "!\n";
        d.mana -= cost;
    }
}
void lumricochet(fighter& tg) {
    int cost = 55;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        cout << d.name << " launches a VERY powerful knife at " << tg.name << "!\n";
        if (random < tg.spd) {
            cout << d.name << "'s attack missed!\n";
        }
        else {
            damage = round(hdrng * d.atk) - tg.def;
            if (damage <= 0) {
                cout << d.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                tg.hp -= damage;
            }
            cout << d.name << "'s knife hits " << tg.name << " and deals " << damage << " damage while reducing their stats by 20%!\n";
            tg.atk -= floor(tg.atk / 5);
            tg.def -= floor(tg.def / 5);
            tg.mana -= floor(tg.mana / 5);
            tg.special -= floor(tg.special / 5);
        }
        d.mana -= cost;
    }
}
void imagtime(fighter& tg) {
    int cost = 10;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < tg.spd) {
            cout << d.name << "'s attack missed!\n";
        }
        else {
            damage = round(mdrng * d.atk) - tg.def;
            if (damage <= 0) {
                cout << d.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                tg.hp -= damage;
                cout << d.name << " throws a frozen knife at " << tg.name << ", dealing " << damage << " damage!\n";
            }
        }
        d.mana -= cost;
    }
}
void fantakiller(fighter& tg) {
    int cost = 22;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        damage = round(hdrng * d.atk) - tg.def;
        if (damage <= 0) {
            cout << d.name << "'s attack hits, but deals 0 damage!\n";
        }
        else {
            tg.hp -= damage;
            cout << d.name << " launches homing knives at " << tg.name << ", dealing " << damage << " damage!\n";
        }
        d.mana -= cost;
    }
}
void soulsculp(fighter& tg) {
    int cost = 11;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < tg.spd) {
            cout << d.name << "'s attack missed!\n";
        }
        else {
            damage = round(mdrng * d.atk) - tg.def;
            if (damage <= 0) {
                cout << d.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                tg.hp -= damage;
                cout << d.name << " slashes 23 times at " << tg.name << ", dealing " << damage << " damage!\n";
            }
        }
        d.mana -= cost;
    }
}
void cricochet(fighter& tg) {
    int cost = 40;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        cout << d.name << " throws a purple knife at " << tg.name << "!\n";
        if (random < tg.spd) {
            cout << d.name << "'s attack missed!\n";
        }
        else {
            damage = round(3 * mdrng * d.atk) - tg.def;
            if (damage <= 0) {
                cout << d.name << "'s attack hits, but " << tg.name << " is too formidable of a foe to care!\n";
            }
            else {
                tg.hp -= damage;
                cout << d.name << "'s knife deals " << damage << " damage to " << tg.name << "!\n";
            }
        }
        d.mana -= cost;
    }
}
void jackdababy(fighter& tg) {
    int cost = 18;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < tg.spd) {
            cout << d.name << "'s attack missed!\n";
        }
        else {
            damage = round(mdrng * d.atk) - tg.def;
            if (damage <= 0) {
                cout << d.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                tg.hp -= damage;
                cout << d.name << " throws several magic orbs at " << tg.name << ", dealing " << damage << " damage! ";
                damage = 5;
                tg.def -= damage;
                cout << tg.name << " also loses " << damage << " DEF!\n";
            }
        }
        d.mana -= cost;
    }
}
void lastresort(int& x, fighter& tg) {
    int cost = 25;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        x++;
        cout << d.name << "feels cornered...\n";
        d.mana -= cost;
    }
}
void sakworld(int& x, fighter& tg) {
    int cost = 20;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < tg.spd) {
            cout << d.name << "'s attack missed!\n";
        }
        else {
            x += 2;
            cout << d.name << " stops time around " << tg.name << " for " << x << " rounds!\n";
        }
        d.mana -= cost;
    }
}
void statsteal(fighter& tg) {
    int cost = 32;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        cout << d.name << " throws 4 knives towards " << tg.name << "!\n";
        int tdmg = 0;
        int k = 0, j = 1;
        for (int i = 0; i < 4; i++) {
            genrngs();
            if (random < tg.spd) {
                cout << d.name << "'s knife missed!\n";
            }
            else {
                damage = round(ldrng * d.atk) - tg.def;
                if (damage <= 0) {
                    cout << d.name << "'s knife hits, but deals 0 damage!\n";
                }
                else {
                    tg.hp -= damage;
                    cout << d.name << "'s knife hits " << tg.name << " for " << damage << " damage!\n";
                    tdmg += damage;
                }
                k += j;
            }
            j *= 10;
            Sleep(100);
        }
        cout << d.name << " deals a total of " << tdmg << " damage to " << tg.name << " and steals some stats!\n";
        d.mana -= cost;
        if (k % 10 == 1) {
            damage = 50;
            tg.hp -= damage;
            d.hp += damage;
        }
        if (k % 100 / 10 == 1) {
            damage = 10;
            tg.mana -= damage;
            d.mana += damage;
        }
        if (k % 1000 / 100 == 1) {
            damage = 1;
            tg.spd -= damage;
            d.spd += damage;
        }
        if (k / 1000 == 1) {
            damage = 5;
            tg.def -= damage;
            d.def += damage;
        }
    }
}
void lunadialII(int& x) {
    int cost = 15;
    if (d.special2 < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        x = 1;
        SetConsoleTextAttribute(hConsole, 4);
        cout << d.name << " readies their gold watch!\n";
        SetConsoleTextAttribute(hConsole, 7);
        d.special2 -= cost;
    }
}
void cringeassault(fighter& tg) {
    int cost = 6;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        if (random < tg.spd) {
            cout << d.name << "'s attack missed!\n";
        }
        else {
            damage = round(mdrng * d.atk) - tg.def;
            if (damage <= 0) {
                cout << d.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                tg.hp -= damage;
                cout << d.name << " uppercuts " << tg.name << ", dealing " << damage << " damage!\n";
            }
        }
        d.mana -= cost;
    }
}
void pushment(int& x, fighter& tg) {
    int cost = 40;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    }
    else {
        x = 3;
        cout << d.name << " curses " << tg.name << " with " << x << " rounds of overwhelming regrets due to a minor mistake!\n";
        d.mana -= cost;
    }
}

/*Function template:
* For the first fighter:
void spellname(fighter& b){
    int cost = //Cost;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    } else {
        if (random < b.spd - a.special / luckhitrate) {
            cout << a.name << "'s attack missed!\n";
        } else {
            //Damage calculation. Usual medium attack: damage = round(mdrng * a.atk) - b.def;
            if (damage <= 0) {
                cout << a.name << "'s attack hits, but deals 0 damage!\n";
            } else {
                //Result. b.hp -= damage;
            }
        }
        a.mana -= cost;
    }
}
* For the second fighter:
void spellname(fighter& a){
    int cost = //Cost;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    } else {
        if (random < a.spd) {
            cout << b.name << "'s attack missed!\n";
        } else {
            //Damage calculation. Usual medium attack: damage = round(mdrng * (b.atk + b.special / hatedmgrate)) - a.def;
            if (damage <= 0) {
                cout << b.name << "'s attack hits, but deals 0 damage!\n";
            } else {
                //Result. a.hp -= damage;
            }
        }
        b.mana -= cost;
    }
}
* Fighter I, Phase II:
void spellname(){
    int cost = //Cost;
    if (a.special2 < cost) {
        cout << "Not enough  A N G E R Y ! ! !\n";
        turn--; repeat = 1;
    } else {
        if (random < b.spd - a.special / luckhitrate) {
            cout << a.name << "'s attack missed!\n";
        } else {
            //Damage calculation. Usual medium attack: damage = round((mdrng + (double)a.special / luckdmgrate) * a.atk) - b.def;
            if (damage <= 0) {
                cout << a.name << "'s attack hits, but deals 0 damage!\n";
            } else {
                //Result. b.hp -= damage;
            }
        }
        a.special2 -= cost;
    }
}
* Fighter II, Phase II:
void spellname(){
    int cost = //Cost;
    if (b.special2 < cost) {
        cout << "Not enough FEAR...\n";
        turn--; repeat = 1;
    } else {
        if (random < a.spd) {
            cout << b.name << "'s attack missed!\n";
        } else {
            //Damage calculation. Usual medium attack: damage = round(mdrng * (b.atk + b.special / hatedmgrate)) - a.def;
            if (damage <= 0) {
                cout << b.name << "'s attack hits, but deals 0 damage!\n";
            } else {
                //Result. a.hp -= damage;
            }
        }
        b.special2 -= cost;
    }
}

* Universal [MP cost]:

void spellname(fighter& tg){
    int cost = //Cost;
    if (PLACEHOLDER.mana < cost) {
        cout << "Not enough mana!\n";
        turn--; repeat = 1;
    } else {
        if (random < tg.spd) {
            cout << PLACEHOLDER.name << "'s attack missed!\n";
        } else {
            //Damage calculation. Usual medium attack: damage = round(mdrng * PLACEHOLDER.atk) - tg.def;
            if (damage <= 0) {
                cout << PLACEHOLDER.name << "'s attack hits, but deals 0 damage!\n";
            } else {
                //Result. tg.hp -= damage;
            }
        }
        PLACEHOLDER.mana -= cost;
    }
}*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
