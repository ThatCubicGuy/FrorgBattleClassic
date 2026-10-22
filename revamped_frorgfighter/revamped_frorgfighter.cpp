#include <iostream>
#include <random>
#include <cmath>
#include <cstring>

using namespace std;
random_device dev;
mt19937 rng(dev());
uniform_int_distribution<uint32_t> uint_dist15(1, 15);
uniform_int_distribution<uint32_t> uint_dist32767(0, 32767);
int damage, spell, turn = 1, luckdmgrate = 2147483647, luckhitrate = 10, hatedmgrate = 2, atkth16 = 90, repeat = 0, cm1 = 0;
double prng, hdrng, mdrng, ldrng;
char p1, p2;
void genrngs() {
    prng = (double)uint_dist32767(rng) * 100 / 32767;
    ldrng = (double)uint_dist32767(rng) / 32767 / 5 + 0.6;
    mdrng = (double)uint_dist32767(rng) / 32767 / 5 + 0.9;
    hdrng = (double)uint_dist32767(rng) / 32767 / 5 + 1.2;
}
class fighter {
public:
    int hp = 1000, maxhp = 1000, exhp = 0, atk = 100, def = 30, spd = 10, mana = 100, special = 0, special2 = 0, phase = 1, noheal = 0, poison = 0, rskip = 0, karma = 0, dodged = 0,
        silenced = 0, reversed = 0, stole = 0, fspell = 0, delspell = 0, counter = 0, temphp = 0, tempmana = 0, tempspd = 0, stamina = 0;
    string name, specialn, special2n;
    fighter(string n, string s1, string s2) {
        name = n;
        specialn = s1;
        special2n = s2;
    }
    friend ostream& operator<<(ostream& os, const fighter& x);
};
fighter a("f r o r g", "LUCK", " A N G E R Y ! ! !"), b("TODD", "HATE", "FEAR..."), c("Player", "???", "CORRUPTION"), d("Sakuya", "Time Gauge", "null"), e("SS Chara", "HATE", "DETERMINATION");
//Misc
void swapAll(fighter& a, fighter& b);
void skipturn(fighter& x);
void skipturnII(fighter& x);
//Fighter 1 [f r o r g]
int reversecard(int& x, fighter& b);
int lottery(fighter& b);
int thirst(fighter& b);
int bslap(fighter& b);
int barf(fighter& b);
int misfortune(fighter& b);
int wakeupslap(fighter& b);
int tornado(fighter& b);
int rain(int& x, fighter& b);
int slice(fighter& b);
int bababooey(fighter& b);
int boing(int& x, fighter& b);
int aneurysm(fighter& b);
int ghost(int& x, fighter& b);
int oneshot(fighter& b);
int bludgeon(fighter& b);
int frogstuffs(fighter& b);
int shutup(int& x, fighter& b);
int diediediedie(fighter& b);
int fin(fighter& b);
//Fighter 2 [TODD]
int multislash(fighter& a);
int sharpprec(fighter& a);
int wound(fighter& a);
int illusion(fighter& a);
int vampwatch(fighter& a);
int detunleashed(fighter& a);
int pslam(fighter& a);
int kheal();
int summonknives(fighter& a);
int lunadial(int& x);
int knifeslash(fighter& a);
int ro_tat_e(fighter& a);
int karmabeach(fighter& a);
int notmydna(int& x, fighter& a);
int backstab(fighter& a);
//Fighter 3 [Player]
int faketp(fighter& tg);
int darkblast(fighter& tg);
int creepvine(int& x, fighter& tg);
int multiblast(fighter& tg);
int ghosttoss(fighter& tg);
int realknife(fighter& tg);
int srsproblem(fighter& tg);
int fkoff(int& x, fighter& tg);
int wannaknow(fighter& tg);
int codesteal(int& x, fighter& tg);
int boring(fighter& tg);
int actdelete(int& x);
//Fighter 4 [Sakuya]
int illsign(fighter& tg);
int slvsign(fighter& tg);
int eternalmek(fighter& tg);
int lumricochet(fighter& tg);
int imagtime(fighter& tg);
int fantakiller(fighter& tg);
int soulsculp(fighter& tg);
int cricochet(fighter& tg);
int jackdababy(fighter& tg);
int lastresort(int& x, fighter& tg);
int sakworld(int& x, fighter& tg);
int statsteal(fighter& tg);
int lunadialII(int& x);
int maidassault(fighter& tg);
int punishment(int& x, fighter& tg);

int hConsole = 0;
void SetConsoleTextAttribute(int shift, int color) {
    int i = 30;
    color = (color + shift) % 8;
    if (color < 8) i += color;
    else i += color + 2;
    cout << "\e[" << i << 'm';
}

// Source - https://stackoverflow.com/a/10613664
// Posted by HighCommander4, modified by community. See post 'Timeline' for change history
// Retrieved 2026-10-13, License - CC BY-SA 3.0
#include <thread>
#include <chrono>
void Sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

ostream& operator<<(ostream& os, const fighter& x) {
    os << x.name;
    if (x.name.length() < 8) os << '\t';
    os << "\t[";
    if (x.karma > 0) {
        SetConsoleTextAttribute(hConsole, 13);
        os << x.hp + x.exhp << " KR, ";
        SetConsoleTextAttribute(hConsole, cm1);
    }
    else os << x.hp + x.exhp << " HP, ";
    os << x.atk << " ATK, " << x.def << " DEF, " << x.spd << " SPD, " << x.mana << " MP]";
    if (x.special > 0) os << " === " << x.special << "% " << x.specialn;
    if (x.phase > 1) os << " - " << x.special2 << "% " << x.special2n;
    SetConsoleTextAttribute(hConsole, 7);
    return os;
}

int main()
{
    int raining = 0, rain2 = 0, rain3 = 0, scd = 0; const int MAXSP = 21; short scdv1[MAXSP] = { 0 }, scdv2[MAXSP] = { 0 }, hc = 1;
    c.def = 25, c.maxhp = 9999, d.hp = d.maxhp = 2500, e.hp = e.maxhp = 700, e.stamina = 300;
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
    while (home.hp + home.exhp > 0 && guest.hp + guest.exhp > 0) {
        genrngs();
        for (int i = 0; i < MAXSP; i++) {
            if (scdv1[i]) scdv1[i]--;
            if (scdv2[i]) scdv2[i]--;
        }
        c.karma = 0;
        if (e.phase == 1) e.temphp = e.hp;
        if (home.karma) {
            home.hp -= 10;
            home.karma--;
        }
        if (guest.karma) {
            guest.hp -= 10;
            guest.karma--;
        }
        SetConsoleTextAttribute(hConsole, 10); cm1 = 10;
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
        SetConsoleTextAttribute(hConsole, 12); cm1 = 12;
        cout << "\n" << guest << "\n";
        SetConsoleTextAttribute(hConsole, 7);
        if (turn % 2 == 1) {
            //Player 1's turn
            genrngs();
            scd = -1;
            //UNO Skip card
            if (home.rskip > 0) {
                home.rskip--;
                SetConsoleTextAttribute(hConsole, 4);
                cout << home.name << " cannot use a spell yet!\n";
                SetConsoleTextAttribute(hConsole, 7);
                scd = 0;
            }
            //Influence setups for p1's attacks
            if (guest.dodged) {
                guest.tempspd = guest.spd;
                guest.spd = 1000;
            }
            if (guest.silenced) {
                home.tempmana = home.mana;
                home.mana = 0;
            }
            if (guest.stole) {
                swapAll(home, guest);
                swap(home.name, guest.name);
            }
            if (guest.reversed) {
                swapAll(home, guest);
            }
            if (guest.delspell) {
                spell = uint_dist15(rng);
                scdv1[spell] += 10;
                //hc = 0;
                SetConsoleTextAttribute(hConsole, 9);
                cout << guest.name << " deletes a random spell from ";
                cout << home.name << "! The selected spell is " << spell << "!\n";
                SetConsoleTextAttribute(hConsole, 7);
                guest.delspell--;
            }
            while (scd == -1) {
                if (guest.fspell == 1) {
                    hc = 0;
                    spell = uint_dist15(rng);
                    cout << home.name << " is forced to use a random spell! The selected spell is " << spell << "!\n";
                    if ((p1 == 'c') && spell > 12) {
                        cout << "Uh oh! " << c.name << " doesn't have that many spells! Rerolling...";
                        spell = 999;
                    }
                }
                if (guest.stole == 1) {
                    spell = uint_dist15(rng);
                    hc = 0;
                    SetConsoleTextAttribute(hConsole, 9);
                    cout << home.name << " steals a random spell from ";
                    cout << guest.name << "! The selected spell is " << spell << "!\n";
                    if ((p1 == 'c') && spell > 12) {
                        cout << "Uh oh! " << c.name << " doesn't have that many spells! Rerolling...";
                        spell = 999;
                    }
                }
                if (hc) {
                    if (home.phase == 2) {
                        cout << home.name;
                        SetConsoleTextAttribute(hConsole, 6);
                        cout << " [PHASE II] ";
                        SetConsoleTextAttribute(hConsole, 7);
                        cout << "uses: ";
                        cin >> spell;
                    }
                    else {
                        cout << home.name << " uses: ";
                        cin >> spell;
                    }
                }
                if (scdv1[spell]) {
                    cout << "That spell cannot be used for another " << ceil((float)scdv1[spell] / 2) << " round";
                    if (ceil((float)scdv1[spell] / 2) != 1) cout << 's';
                    cout << "!\n";
                    scd = -1;
                }
                else {
                    switch (p1) {
                    case 'a':
                        switch (spell) {
                        case 1:
                            scd = reversecard(home.reversed, guest);
                            break;
                        case 2:
                            scd = lottery(guest);
                            break;
                        case 3:
                            scd = thirst(guest);
                            break;
                        case 4:
                            scd = bslap(guest);
                            break;
                        case 5:
                            scd = barf(guest);
                            break;
                        case 6:
                            scd = misfortune(guest);
                            break;
                        case 7:
                            scd = wakeupslap(guest);
                            break;
                        case 8:
                            scd = tornado(guest);
                            break;
                        case 9:
                            scd = rain(raining, guest);
                            break;
                        case 10:
                            scd = slice(guest);
                            break;
                        case 11:
                            scd = bababooey(guest);
                            break;
                        case 12:
                            scd = boing(guest.rskip, guest);
                            break;
                        case 13:
                            scd = aneurysm(guest);
                            break;
                        case 14:
                            scd = ghost(home.fspell, guest);
                            break;
                        case 15:
                            scd = oneshot(guest);
                            break;
                        case 16:
                            scd = bludgeon(guest);
                            break;
                        case 17:
                            scd = frogstuffs(guest);
                            break;
                        case 18:
                            scd = shutup(home.silenced, guest);
                            break;
                        case 19:
                            scd = diediediedie(guest);
                            break;
                        case 20:
                            scd = fin(guest);
                            break;
                        case 999:
                            break;
                        default:
                            if (home.phase == 1) skipturn(home);
                            else skipturnII(home);
                            scd = 0;
                        }
                        break;
                    case 'b':
                        switch (spell) {
                        case 1:
                            scd = multislash(guest);
                            break;
                        case 2:
                            scd = sharpprec(guest);
                            break;
                        case 3:
                            scd = wound(guest);
                            break;
                        case 4:
                            scd = illusion(guest);
                            break;
                        case 5:
                            scd = vampwatch(guest);
                            break;
                        case 6:
                            scd = detunleashed(guest);
                            break;
                        case 7:
                            scd = pslam(guest);
                            break;
                        case 8:
                            scd = kheal();
                            break;
                        case 9:
                            scd = summonknives(guest);
                            break;
                        case 10:
                            scd = lunadial(home.dodged);
                            break;
                        case 11:
                            scd = knifeslash(guest);
                            break;
                        case 12:
                            scd = ro_tat_e(guest);
                            break;
                        case 13:
                            scd = karmabeach(guest);
                            break;
                        case 14:
                            scd = notmydna(home.stole, guest);
                            break;
                        case 15:
                            scd = backstab(guest);
                            break;
                        case 999:
                            break;
                        default:
                            if (home.phase == 1) skipturn(home);
                            else skipturnII(home);
                            scd = 0;
                        }
                        break;
                    case 'c':
                        switch (spell) {
                        case 1:
                            scd = faketp(guest);
                            break;
                        case 2:
                            scd = darkblast(guest);
                            break;
                        case 3:
                            scd = creepvine(guest.rskip, guest);
                            break;
                        case 4:
                            scd = multiblast(guest);
                            break;
                        case 5:
                            scd = ghosttoss(guest);
                            break;
                        case 6:
                            scd = realknife(guest);
                            break;
                        case 7:
                            scd = srsproblem(guest);
                            break;
                        case 8:
                            scd = fkoff(rain2, guest);
                            break;
                        case 9:
                            scd = wannaknow(guest);
                            break;
                        case 10:
                            scd = codesteal(home.delspell, guest);
                            break;
                        case 11:
                            scd = boring(guest);
                            break;
                        case 12:
                            scd = actdelete(home.dodged);
                            break;
                        case 999:
                            break;
                        default:
                            if (home.phase == 1) skipturn(home);
                            else skipturnII(home);
                            scd = 0;
                        }
                        break;
                    case 'd':
                        switch (spell) {
                        case 1:
                            scd = illsign(guest);
                            break;
                        case 2:
                            scd = slvsign(guest);
                            break;
                        case 3:
                            scd = eternalmek(guest);
                            break;
                        case 4:
                            scd = lumricochet(guest);
                            break;
                        case 5:
                            scd = imagtime(guest);
                            break;
                        case 6:
                            scd = fantakiller(guest);
                            break;
                        case 7:
                            scd = soulsculp(guest);
                            break;
                        case 8:
                            scd = cricochet(guest);
                            break;
                        case 9:
                            scd = jackdababy(guest);
                            break;
                        case 10:
                            scd = lastresort(home.counter, guest);
                            break;
                        case 11:
                            scd = sakworld(guest.rskip, guest);
                            break;
                        case 12:
                            scd = statsteal(guest);
                            break;
                        case 13:
                            scd = lunadialII(home.dodged);
                            break;
                        case 14:
                            scd = maidassault(guest);
                            break;
                        case 15:
                            scd = punishment(rain3, guest);
                            break;
                        case 999:
                            break;
                        default:
                            skipturn(home);
                            scd = 0;
                        }
                        break;
                    case 'e':
                        switch (spell) {
                        case 999:
                            break;
                        default:
                            skipturn(home);
                            scd = 0;
                        }
                        break;
                    }
                }
            }
            guest.fspell = 0;
            hc = 1;
            scdv1[spell] += scd * 2;
            if (guest.stole == 1) {
                swapAll(home, guest);
                swap(home.name, guest.name);
                SetConsoleTextAttribute(hConsole, 7);
                guest.stole = 0;
            }
            //Dodge / reverse checks for p1's attacks
            if (guest.dodged > 0) {
                guest.spd = guest.tempspd;
                if (p2 == 'b') cout << guest.name << " uses their watch to dodge " << home.name << "'s attack!\n";
                else if (p2 == 'c') cout << guest.name << " uses their console to delete " << home.name << "'s attack!\n";
                guest.dodged--;
            }
            if (guest.reversed > 0) {
                swapAll(home, guest);
                SetConsoleTextAttribute(hConsole, 9);
                cout << home.name << "'s spell was reversed! Every effect was applied to them instead!\n";
                SetConsoleTextAttribute(hConsole, 7);
                guest.reversed--;
            }
            if (guest.silenced > 0) {
                home.mana = home.tempmana;
                SetConsoleTextAttribute(hConsole, 9);
                cout << home.name << " is no longer silenced!\n";
                SetConsoleTextAttribute(hConsole, 7);
                guest.silenced--;
            }
            if (home.counter) {
                home.temphp = home.hp;
            }
            if (guest.counter && guest.temphp != guest.hp) {
                int healpw = 500;
                SetConsoleTextAttribute(hConsole, 9);
                cout << guest.name << " used a counter! " << home.name << "'s foolish attack helped " << guest.name << " recover!\n";
                SetConsoleTextAttribute(hConsole, 7);
                guest.hp = guest.temphp + healpw;
            }
            guest.counter = 0;
        }
        else {
            //Player 2's turn
            genrngs();
            scd = -1;
            //UNO Skip card
            if (guest.rskip > 0) {
                guest.rskip--;
                SetConsoleTextAttribute(hConsole, 4);
                cout << guest.name << " cannot use a spell yet!\n";
                SetConsoleTextAttribute(hConsole, 7);
                scd = 0;
            }
            //Influence setups for p2's attacks
            if (home.dodged) {
                home.tempspd = home.spd;
                home.spd = 1000;
            }
            if (home.silenced) {
                guest.tempmana = guest.mana;
                guest.mana = 0;
            }
            if (home.stole) {
                swapAll(home, guest);
                swap(home.name, guest.name);
            }
            if (home.reversed) {
                swapAll(home, guest);
            }
            if (home.delspell) {
                spell = uint_dist15(rng);
                scdv2[spell] += 10;
                //hc = 0;
                SetConsoleTextAttribute(hConsole, 9);
                cout << home.name << " deletes a random spell from ";
                cout << guest.name << "! The selected spell is " << spell << "!\n";
                SetConsoleTextAttribute(hConsole, 7);
                home.delspell--;
            }
            while (scd == -1) {
                if (home.fspell == 1) {
                    hc = 0;
                    spell = uint_dist15(rng);
                    cout << guest.name << " is forced to use a random spell! The selected spell is " << spell << "!\n";
                    if ((p2 == 'c') && spell > 12) {
                        cout << "Uh oh! " << c.name << " doesn't have that many spells! Rerolling...";
                        spell = 999;
                        home.fspell = 1;
                    }
                }
                if (home.stole == 1) {
                    spell = uint_dist15(rng);
                    hc = 0;
                    SetConsoleTextAttribute(hConsole, 9);
                    cout << guest.name << " steals a random spell from ";
                    cout << home.name << "! The selected spell is " << spell << "!\n";
                    if ((p2 == 'c') && spell > 12) {
                        cout << "Uh oh! " << c.name << " doesn't have that many spells! Rerolling...";
                        spell = 999;
                    }
                }
                if (hc) {
                    if (guest.phase == 2) {
                        cout << guest.name;
                        SetConsoleTextAttribute(hConsole, 6);
                        cout << " [PHASE II] ";
                        SetConsoleTextAttribute(hConsole, 7);
                        cout << "uses: ";
                        cin >> spell;
                    }
                    else {
                        cout << guest.name << " uses: ";
                        cin >> spell;
                    }
                }
                if (scdv2[spell]) {
                    cout << "That spell is on cooldown for " << ceil((float)scdv2[spell] / 2) << " more round";
                    if (ceil((float)scdv2[spell] / 2) != 1) cout << 's';
                    cout << "!\n";
                    scd = -1;
                }
                else {
                    switch (p2) {
                    case 'a':
                        switch (spell) {
                        case 1:
                            scd = reversecard(home.reversed, home);
                            break;
                        case 2:
                            scd = lottery(home);
                            break;
                        case 3:
                            scd = thirst(home);
                            break;
                        case 4:
                            scd = bslap(home);
                            break;
                        case 5:
                            scd = barf(home);
                            break;
                        case 6:
                            scd = misfortune(home);
                            break;
                        case 7:
                            scd = wakeupslap(home);
                            break;
                        case 8:
                            scd = tornado(home);
                            break;
                        case 9:
                            scd = rain(raining, home);
                            break;
                        case 10:
                            scd = slice(home);
                            break;
                        case 11:
                            scd = bababooey(home);
                            break;
                        case 12:
                            scd = boing(home.rskip, home);
                            break;
                        case 13:
                            scd = aneurysm(home);
                            break;
                        case 14:
                            scd = ghost(guest.fspell, home);
                            break;
                        case 15:
                            scd = oneshot(home);
                            break;
                        case 16:
                            scd = bludgeon(home);
                            break;
                        case 17:
                            scd = frogstuffs(home);
                            break;
                        case 18:
                            scd = shutup(guest.silenced, home);
                            break;
                        case 19:
                            scd = diediediedie(home);
                            break;
                        case 20:
                            scd = fin(home);
                            break;
                        case 999:
                            break;
                        default:
                            if (guest.phase == 1) skipturn(guest);
                            else skipturnII(guest);
                            scd = 0;
                        }
                        break;
                    case 'b':
                        switch (spell) {
                        case 1:
                            scd = multislash(home);
                            break;
                        case 2:
                            scd = sharpprec(home);
                            break;
                        case 3:
                            scd = wound(home);
                            break;
                        case 4:
                            scd = illusion(home);
                            break;
                        case 5:
                            scd = vampwatch(home);
                            break;
                        case 6:
                            scd = detunleashed(home);
                            break;
                        case 7:
                            scd = pslam(home);
                            break;
                        case 8:
                            scd = kheal();
                            break;
                        case 9:
                            scd = summonknives(home);
                            break;
                        case 10:
                            scd = lunadial(guest.dodged);
                            break;
                        case 11:
                            scd = knifeslash(home);
                            break;
                        case 12:
                            scd = ro_tat_e(home);
                            break;
                        case 13:
                            scd = karmabeach(home);
                            break;
                        case 14:
                            scd = notmydna(guest.stole, home);
                            break;
                        case 15:
                            scd = backstab(home);
                            break;
                        case 999:
                            break;
                        default:
                            if (guest.phase == 1) skipturn(guest);
                            else skipturnII(guest);
                            scd = 0;
                        }
                        break;
                    case 'c':
                        switch (spell) {
                        case 1:
                            scd = faketp(home);
                            break;
                        case 2:
                            scd = darkblast(home);
                            break;
                        case 3:
                            scd = creepvine(home.rskip, home);
                            break;
                        case 4:
                            scd = multiblast(home);
                            break;
                        case 5:
                            scd = ghosttoss(home);
                            break;
                        case 6:
                            scd = realknife(home);
                            break;
                        case 7:
                            scd = srsproblem(home);
                            break;
                        case 8:
                            scd = fkoff(rain2, home);
                            break;
                        case 9:
                            scd = wannaknow(home);
                            break;
                        case 10:
                            scd = codesteal(guest.delspell, home);
                            break;
                        case 11:
                            scd = boring(home);
                            break;
                        case 12:
                            scd = actdelete(guest.dodged);
                            break;
                        case 999:
                            break;
                        default:
                            if (guest.phase == 1) skipturn(guest);
                            else skipturnII(guest);
                            scd = 0;
                        }
                        break;
                    case 'd':
                        switch (spell) {
                        case 1:
                            scd = illsign(home);
                            break;
                        case 2:
                            scd = slvsign(home);
                            break;
                        case 3:
                            scd = eternalmek(home);
                            break;
                        case 4:
                            scd = lumricochet(home);
                            break;
                        case 5:
                            scd = imagtime(home);
                            break;
                        case 6:
                            scd = fantakiller(home);
                            break;
                        case 7:
                            scd = soulsculp(home);
                            break;
                        case 8:
                            scd = cricochet(home);
                            break;
                        case 9:
                            scd = jackdababy(home);
                            break;
                        case 10:
                            scd = lastresort(guest.counter, home);
                            break;
                        case 11:
                            scd = sakworld(home.rskip, home);
                            break;
                        case 12:
                            scd = statsteal(home);
                            break;
                        case 13:
                            scd = lunadialII(guest.dodged);
                            break;
                        case 14:
                            scd = maidassault(home);
                            break;
                        case 15:
                            scd = punishment(rain3, home);
                            break;
                        case 999:
                            break;
                        default:
                            skipturn(guest);
                            scd = 0;
                        }
                        break;
                    case 'e':
                        switch (spell) {
                        case 999:
                            break;
                        default:
                            skipturn(guest);
                            scd = 0;
                        }
                        break;
                    }
                }
            }
            home.fspell = 0;
            hc = 1;
            scdv2[spell] += scd * 2;
            if (home.stole == 1) {
                swapAll(home, guest);
                swap(home.name, guest.name);
                SetConsoleTextAttribute(hConsole, 7);
                home.stole = 0;
            }
            //Dodge / reverse checks for p2's attacks
            if (home.dodged > 0) {
                home.spd = home.tempspd;
                SetConsoleTextAttribute(hConsole, 9);
                if (p1 == 'b') cout << home.name << " uses their watch to dodge " << guest.name << "'s attack!\n";
                else if (p1 == 'c') cout << home.name << " uses their console to delete " << guest.name << "'s attack!\n";
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
            if (guest.counter) {
                guest.temphp = guest.hp;
            }
            if (home.counter && home.temphp != home.hp) {
                int healpw = 500;
                SetConsoleTextAttribute(hConsole, 8);
                cout << home.name << " used a counter! " << guest.name << "'s foolish attack helped " << home.name << " recover!\n";
                SetConsoleTextAttribute(hConsole, 7);
                home.hp = home.temphp + healpw;
            }
            home.counter = 0;
            //Full round actions
            home.mana += 5; guest.mana += 5;
            a.special2++, b.special2 += 5, c.special2 += 5;
            if (raining > 0) {
                int manaboost = 15, hpboost = 30, hploss = 10, atkloss = 5;
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
                    guest.atk -= atkloss;
                }
                else {
                    cout << home.name << " loses " << hploss << " HP and " << atkloss << " ATK!\n";
                    home.hp -= hploss;
                    home.atk -= atkloss;
                }
                SetConsoleTextAttribute(hConsole, 7);
                a.mana += manaboost;
                a.hp += hpboost;
                raining--;
            }
            if (rain2 > 0) {
                int hpboost = 20, manaboost = 5, defboost = 2, spdboost = 0;
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
                cout << c.name << " gains " << manaboost << " MP, " << defboost << " DEF and " << hpboost << " HP!\n";
                SetConsoleTextAttribute(hConsole, 4);
                if (p1 == 'c') {
                    cout << guest.name << " loses these stats!\n";
                    guest.hp -= hpboost;
                    guest.mana -= manaboost;
                    guest.def -= defboost;
                    home.hp += hpboost;
                    home.mana += manaboost;
                    home.def += defboost;
                }
                else {
                    cout << home.name << " loses these stats!\n";
                    home.hp -= hpboost;
                    home.mana -= manaboost;
                    home.def -= defboost;
                    guest.hp += hpboost;
                    guest.mana += manaboost;
                    guest.def += defboost;
                }
                SetConsoleTextAttribute(hConsole, 7);
                rain2--;
            }
            if (rain3 > 0) {
                int hpboost = 50, manaboost = 10, atkboost = 5, defboost = 5;
                SetConsoleTextAttribute(hConsole, 14);
                cout << "The regrets make ";
                if (p1 == 'd') cout << guest.name << " suffer!\n";
                else cout << home.name << " suffer!\n";
                SetConsoleTextAttribute(hConsole, 4);
                if (p1 == 'd') {
                    cout << guest.name << " loses " << hpboost << " HP, " << manaboost << " mana, " << defboost << " DEF and " << atkboost << " ATK!\n";
                    guest.hp -= hpboost;
                    guest.mana -= manaboost;
                    guest.atk -= atkboost;
                    guest.def -= defboost;
                }
                else {
                    cout << home.name << " loses " << hpboost << " HP, " << manaboost << " mana, " << defboost << " DEF and " << atkboost << " ATK!\n";
                    home.hp -= hpboost;
                    home.mana -= manaboost;
                    home.atk -= atkboost;
                    home.def -= defboost;
                }
                SetConsoleTextAttribute(hConsole, 7);
                rain3--;
            }
        }
        turn++;
        //Cap checks
        if (home.hp > home.maxhp) home.hp = home.maxhp;
        if (guest.hp > guest.maxhp) guest.hp = guest.maxhp;
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
        //Cap ignorant stuff
        if (home.hp + home.exhp < home.maxhp) home.hp += home.exhp, home.exhp = 0;
        if (guest.hp + guest.exhp < guest.maxhp) guest.hp += guest.exhp, guest.exhp = 0;
        //Phase II checks
        if (a.hp < 100 && a.phase == 1) {
            a.phase = 2;
            a.hp = 500;
            a.def = 80;
            a.mana = 90;
            a.special2 = 3;
            SetConsoleTextAttribute(hConsole, 5);
            cout << a.name << " enters PHASE II! They recovered some mana and HP, and their DEF is boosted significantly!\n";
            SetConsoleTextAttribute(hConsole, 7);
        }
        if (b.hp < 100 && b.phase == 1) {
            b.phase = 2;
            b.hp = 500;
            b.atk = 150;
            b.mana = 150;
            b.special2 = 15;
            SetConsoleTextAttribute(hConsole, 5);
            cout << b.name << " enters PHASE II! They recovered some mana and HP, and their ATK is boosted significantly!\n";
            SetConsoleTextAttribute(hConsole, 7);
        }
        if (c.hp < 0 && c.phase == 1) {
            c.phase = 2;
            c.hp = 400;
            c.atk += 20;
            c.def += 20;
            c.mana = 100;
            c.special2 = 15;
            SetConsoleTextAttribute(hConsole, 5);
            cout << c.name << " enters PHASE II! They recovered some mana and HP, and their ATK & DEF are boosted!\n";
            SetConsoleTextAttribute(hConsole, 7);
        }
        if (d.hp < 1250 && d.phase == 1) {
            d.phase = 0;
            d.atk += 10;
            d.def += 10;
            d.mana += 100;
            SetConsoleTextAttribute(hConsole, 5);
            cout << "This fight is taking too long! The mistress may get mad at " << d.name << " if they don't finish this NOW!\n";
            SetConsoleTextAttribute(hConsole, 7);
        }
        if (e.stamina > 0 && e.phase == 1 && e.hp < e.temphp) {
            cout << e.name << " dodges ";
            if (p1 == 'e') cout << guest.name << "'s attack!\n";
            else cout << home.name << "'s attack!\n";
            e.stamina -= 700 - e.hp;
            e.hp = 700;
        }
        if (e.stamina < 0 && e.phase == 1) {
            SetConsoleTextAttribute(hConsole, 5);
            cout << "D-did you just wound " << d.name << "?!\n";
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
    SetConsoleTextAttribute(hConsole, 26);
    if (home.hp > 0) cout << home.name << " wins\n";
    else if (guest.hp > 0) cout << guest.name << " wins\n";
         else if (home.spd > guest.spd) cout << home.name << " wins [SPD]\n";
             else if (guest.spd > home.spd) cout << guest.name << " wins [SPD]\n";
                  else cout << "Draw\n";
    return turn / 2 + turn % 2;
}

//Misc
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
int reversecard(int& x, fighter& b) {
    int cost = 25, cd = 10;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        a.mana -= cost;
        x = 1;
        cout << "Something terrible is about to happen...\n";
    }
    return cd;
}
int lottery(fighter& b) {
    int cost = 15, cd = 3;
    if (a.special < cost) {
        cout << "Not enough LUCK!\n";
        return -1;
    }
    else if (prng < b.spd - a.special / luckhitrate) {
        cout << a.name << " tries to act, but " << b.name << " acts faster!\n";
        a.special -= cost;
    }
    else {
        cout << a.name << " visits the lottery!\n";
        if (prng < 20) {
            damage = 10 * a.atk - b.def;
            if (damage <= 0) {
                cout << a.name << " uses a formidable attack, yet " << b.name << " is able to block it in its entirety, taking 0 damage!\n";
            }
            else {
                b.hp -= damage;
                cout << a.name << " wins the grand prize! " << b.name << " takes " << damage << " damage!\n";
            }
        }
        else if (prng < 40) {
            damage = 2 * a.special;
            if (damage <= 0) {
                cout << a.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                b.hp -= damage;
                cout << a.name << " wins the second prize! " << b.name << " takes " << damage << " damage!\n";
            }
        }
        else if (prng < 60) {
            damage = a.special / 10;
            b.def -= damage;
            cout << a.name << " finds " << b.name << "'s ticket and uses it instead! " << b.name << " loses " << damage << " DEF!\n";
        }
        else if (prng < 80) {
            damage = round(a.special / 50);
            a.spd += damage;
            b.spd -= damage;
            cout << a.name << " steals " << b.name << "'s ticket from right under their nose! " << a.name << " gains " << damage << " SPD!\n";
        }
        else {
            damage = 30;
            a.special -= damage;
            cout << a.name << " spends their money, but wins nothing. " << a.name << " loses " << damage << " LUCK in the process.\n";
        }
        a.special -= cost;
    }
    return cd;
}
int thirst(fighter& b) {
    int cost = 20, cd = 7;
    if (a.special < cost) {
        cout << "Not enough LUCK!\n";
        return -1;
    }
    else {
        damage = 10;
        b.mana -= damage;
        a.mana += damage;
        cout << a.name << " absorbs " << damage << " mana from " << b.name << "!\n";
        a.special -= cost;
    }
    return cd;
}
int bslap(fighter& b) {
    int cost = 16, cd = 3;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        cout << a.name << " slaps " << b.name << "!\n";
        for (int i = 0; i < 1.01 + a.special / luckdmgrate; i++) {
            genrngs();
            if (prng < b.spd - a.special / luckhitrate) {
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
    return cd;
}
int barf(fighter& b) {
    int cost = 15, cd = 4;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        cout << a.name << " did not enjoy their last meal!\n";
        if (prng < b.spd - a.special / luckhitrate) {
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
            damage = 5;
            b.atk -= damage;
            cout << b.name << " loses " << damage << " ATK!\n";
        }
        a.mana -= cost;
    }
    return cd;
}
int misfortune(fighter& b) {
    int cost = 36, cd = 20;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
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
    return cd;
}
int wakeupslap(fighter& b) {
    int cost = 15, cd = 3;
    int hitcount = 20;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
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
                if (prng < b.spd - a.special / luckhitrate) hitcount--;
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
    return cd;
}
int tornado(fighter& b) {
    int cost = 40, cd = 8;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        cout << a.name << " launches a furious tornado towards " << b.name << "!\n";
        if (prng < b.spd - a.special / luckhitrate) {
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
    return cd;
}
int rain(int& x, fighter& b) {
    int cost = 31, cd = 9;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        x = 3;
        cout << a.name << " curses the battlefield with " << x << " rounds of bri'ish rain!\n";
        a.mana -= cost;
    }
    return cd;
}
int slice(fighter& b) {
    int cost = 9, cd = 2;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        cout << a.name << " slices " << b.name << " with their lucky knife!\n";
        if (prng < b.spd - a.special / luckhitrate) {
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
    return cd;
}
int bababooey(fighter& b) {
    int cost = 15, cd = 4;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        cout << a.name << " throws a cat at " << b.name << "!\n";
        if (prng < 50) {
            cout << a.name << "'s cat wanders off into the universe!\n";
        }
        else {
            genrngs();
            if (prng < b.spd - a.special / luckhitrate) {
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
    return cd;
}
int boing(int& x, fighter& b) {
    int cost = 18, cd = 10;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        cout << a.name << " tries to punch " << b.name << " with an extendo grip!\n";
        if (prng < b.spd - a.special / luckhitrate) {
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
            x += 3;
            cout << b.name << " gets shoved " << x << " rounds away!\n";
        }
        a.mana -= cost;
    }
    return cd;
}
int aneurysm(fighter& b) {
    int cost = 25, cd = 6;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        cout << a.name << " types some random gibberish in the chat!\n";
        if (prng < b.spd - a.special / luckhitrate) {
            cout << a.name << "'s attack missed!\n";
        }
        else {
            b.special = b.special2 = 0;
            cout << b.name << " has an aneurysm and loses all their special stats!\n";
        }
        a.mana -= cost;
    }
    return cd;
}
int ghost(int& x, fighter& b) {
    int cost = 10, cd = 9;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        x = 1;
        cout << a.name << " releases a cheeky ghost that seeks " << b.name << " and ruins their plans!\n";
        a.mana -= cost;
    }
    return cd;
}
int oneshot(fighter& b) {
    int cost = 41, cd = 20;
    if (a.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        cout << a.name << " gets MAD at " << b.name << "!\n";
        if (prng < b.spd) {
            int atkboost = 50;
            a.atk += atkboost;
            cout << a.name << " misses their smack and gets EVEN MORE MAD! Their attack is increased by " << atkboost << "!\n";
        }
        else {
            damage = round(3 * hdrng * a.atk) - b.def;
            b.hp -= damage;
            a.hp += floor((damage - floor(damage / 10))/2);
            a.atk += floor(damage / 10);
            cout << a.name << " smacks " << b.name << " directly in the butt, dealing " << damage << " emotional damage, stealing their HP & transforming part of it into ATK!\n";
        }
        a.mana -= cost;
    }
    return cd;
}
int bludgeon(fighter& b) {
    int cost = 3, cd = 6;
    if (a.special2 < cost) {
        cout << "Not enough " << a.special2n << '\n';
        return -1;
    }
    else if (a.atk > atkth16) {
        cout << a.name << " grabs a nearby stick and approaches " << b.name << "!\n";
        for (int i = 0; i < 3; i++) {
            genrngs();
            if (prng < b.spd - a.special / luckhitrate) {
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
    return cd;
}
int frogstuffs(fighter& b) {
    int cost = 2, cd = 10;
    if (a.special2 < cost) {
        cout << "Not enough " << a.special2n << '\n';
        return -1;
    }
    else {
        if (prng < b.spd - a.special / luckhitrate) {
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
    return cd;
}
int shutup(int& x, fighter& b) {
    int cost = 4, cd = 7;
    if (a.special2 < cost) {
        cout << "Not enough " << a.special2n << '\n';
        return -1;
    }
    else {
        x = 1;
        cout << a.name << " makes " << b.name << " shut the fuck up! " << b.name << " cannot use mana for the following round!\n";
        a.special2 -= cost;
    }
    return cd;
}
int diediediedie(fighter& b) {
    int cost = 1, cd = 3;
    if (a.special2 < cost) {
        cout << "Not enough " << a.special2n << '\n';
        return -1;
    }
    else {
        cout << a.name << " lets out some anger on " << b.name << "!\n";
        for (int i = 0; i < 4; i++) {
            genrngs();
            if (prng < b.spd - a.special / luckhitrate) {
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
    return cd;
}
int fin(fighter& b) {
    int cost = 10, cd = 10;
    if (a.special2 < cost) {
        cout << "Not enough " << a.special2n << '\n';
        return -1;
    }
    else {
        cout << a.name << " has had it up to HERE with " << b.name << "!\n";
        if (prng < b.spd - a.special / luckhitrate) {
            cout << a.name << "'s attack did not reach " << b.name << "'s ears!\n";
        }
        else {
            damage = round(5 * mdrng * a.atk) - b.def;
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
    return cd;
}
//Fighter 2
int multislash(fighter& a) {
    int cost = 4, cd = 2;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < a.spd - 10) {
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
    return cd;
}
int sharpprec(fighter& a) {
    int cost = 3, cd = 2;
    if (b.mana < cost) {
        cout << "Not enough mana! Why are you so BROKE!?\n";
        return -1;
    }
    else {
        if (prng < a.spd) {
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
    return cd;
}
int wound(fighter& a) {
    int cost = 15, cd = 3;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < a.spd) {
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
    return cd;
}
int illusion(fighter& a) {
    int cost = 20, cd = 4;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
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
    return cd;
}
int vampwatch(fighter& a) {
    int cost = 17, cd = 3;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < a.spd) {
            cout << b.name << "'s attack misses!\n";
        }
        else {
            damage = round(mdrng * (b.atk + b.special / hatedmgrate)) - a.def;
            if (damage <= 0) {
                cout << b.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                a.hp -= damage;
                b.exhp += damage;
                cout << b.name << " throws a pocket watch at " << a.name << "! They take " << damage << " damage and " << b.name << " steals their HP!\n";
            }
        }
        b.mana -= cost;
    }
    return cd;
}
int detunleashed(fighter& a) {
    int cost = 18, cd = 4;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
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
    return cd;
}
int pslam(fighter& a) {
    int cost = 10, cd = 2;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < a.spd) {
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
    return cd;
}
int kheal() {
    int cost = 25, cd = 15;
    if (b.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        int healpw = 300;
        b.hp += healpw;
        cout << b.name << " heals up " << healpw << " HP using their knife!\n";
        b.mana -= cost;
    }
    return cd;
}
int summonknives(fighter& a) {
    int cost = 5, cd = 3;
    if (b.special2 < cost) {
        cout << "Not enough " << b.special2n << '\n';
        return -1;
    }
    else {
        if (prng < a.spd) {
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
    return cd;
}
int lunadial(int& x) {
    int cost = 15, cd = 8;
    if (b.special2 < cost) {
        cout << "Not enough " << b.special2n << '\n';
        return -1;
    }
    else {
        x = 1;
        SetConsoleTextAttribute(hConsole, 4);
        cout << b.name << " readies their bronze watch!\n";
        SetConsoleTextAttribute(hConsole, 7);
        b.special2 -= cost;
    }
    return cd;
}
int knifeslash(fighter& a) {
    int cost = 10, cd = 4;
    if (b.special2 < cost) {
        cout << "Not enough " << b.special2n << '\n';
        return -1;
    }
    else {
        if (prng < a.spd) {
            cout << b.name << "'s attack missed!\n";
        }
        else {
            damage = round(1.5 * mdrng * (b.atk + b.special / hatedmgrate)) - a.def;
            if (damage <= 0) {
                cout << b.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                a.hp -= damage;
                b.special += damage / 10;
                cout << b.name << " slashes " << a.name << " with thousands of knives, dealing " << damage << " damage and gaining " << damage / 10 << " HATE!\n";
            }
        }
        b.special2 -= cost;
    }
    return cd;
}
int ro_tat_e(fighter& a) {
    int cost = 25, cd = 7;
    int inacc = 40;
    if (b.special2 < cost) {
        cout << "Not enough " << b.special2n << '\n';
        return -1;
    }
    else {
        cout << b.name << " starts RO-TAT-ING!\n";
        for (int i = 0; i < 5; i++) {
            genrngs();
            if (prng < a.spd + inacc) {
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
    return cd;
}
int karmabeach(fighter& a) {
    int cost = 15, cd = 8;
    if (b.special2 < cost) {
        cout << "Not enough " << b.special2n << '\n';
        return -1;
    }
    else {
        if (prng < a.spd) {
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
    return cd;
}
int notmydna(int& x, fighter& a) {
    int cost = 15, cd = 13;
    if (b.special2 < cost) {
        cout << "Not enough " << b.special2n << '\n';
        return -1;
    }
    else {
        x = 1;
        cout << b.name << " \"borrows\" " << a.name << "'s DNA without permission!\n";
        b.special2 -= cost;
    }
    return cd;
}
int backstab(fighter& a) {
    int cost = 25, cd = 7;
    if (b.special2 < cost) {
        cout << "Not enough " << b.special2n << '\n';
        return -1;
    }
    else {
        cout << b.name << " sneaks behind " << a.name << "!\n";
        if (prng < a.spd - 5) {
            cout << b.name << "'s attack missed!\n";
        }
        else {
            damage = floor(a.hp * 3 / 20);
            a.hp -= damage;
            b.hp += damage;
            cout << b.name << " BACKSTABS " << a.name << ", stealing " << damage << " HP, ";
            damage = floor(a.mana / 10);
            a.mana -= damage;
            b.mana += damage;
            cout << damage << " mana and ruining his DEF!\n";
            damage = b.atk / 10;
            a.def -= damage;
        }
        b.special2 -= cost;
    }
    return cd;
}
//Fighter 3
int faketp(fighter& tg) {
    int cost = 6, cd = 2;
    if (c.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < tg.spd) {
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
    return cd;
}
int darkblast(fighter& tg) {
    int cost = 6, cd = 2;
    if (c.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < tg.spd) {
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
    return cd;
}
int creepvine(int& x, fighter& tg) {
    int cost = 18, cd = 10;
    if (c.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < tg.spd) {
            cout << c.name << "'s attack missed!\n";
        }
        else {
            x += 3;
            cout << c.name << " stuns " << tg.name << " with vines for " << x << " rounds!\n";
        }
        c.mana -= cost;
    }
    return cd;
}
int multiblast(fighter& tg) {
    int cost = 14, cd = 3;
    if (c.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < tg.spd) {
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
    return cd;
}
int ghosttoss(fighter& tg) {
    int cost = 9, cd = 2;
    if (c.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < tg.spd) {
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
    return cd;
}
int realknife(fighter& tg) {
    int cost = 3, cd = 1;
    if (c.mana < cost) {
        cout << "Not enough mana! Why are you so BROKE!?\n";
        return -1;
    }
    else {
        if (prng < tg.spd) {
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
    return cd;
}
int srsproblem(fighter& tg) {
    int cost = 13, cd = 3;
    if (c.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < tg.spd) {
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
    return cd;
}
int fkoff(int& x, fighter& tg) {
    int cost = 60, cd = 9;
    if (c.mana < cost) {
        cout << "Not enough corruption?\n";
        return -1;
    }
    else {
        x = 3;
        cout << c.name << " curses " << tg.name << " with " << x << " rounds of corrupted rain!\n";
        c.mana -= cost;
    }
    return cd;
}
int wannaknow(fighter& tg) {
    int cost = 31, cd = 6;
    if (c.special2 < cost) {
        cout << "Not enough corruption?\n";
        return -1;
    }
    else {
        if (prng < tg.spd) {
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
    return cd;
}
int codesteal(int& x, fighter& tg) {
    int cost = 15, cd = 8;
    if (c.special2 < cost) {
        cout << "Not enough corruption?\n";
        return -1;
    }
    else {
        x = 1;
        cout << c.name << " edits " << tg.name << "'s code!\n";
        c.special2 -= cost;
    }
    return cd;
}
int boring(fighter& tg) {
    int cost = 30, cd = 12;
    if (c.special2 < cost) {
        cout << "Not enough corruption?\n";
        return -1;
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
    return cd;
}
int actdelete(int& x) {
    int cost = 15, cd = 7;
    if (c.special2 < cost) {
        cout << "Not enough corruption?\n";
        return -1;
    }
    else {
        x = 1;
        SetConsoleTextAttribute(hConsole, 4);
        cout << c.name << " prepares the console!\n";
        SetConsoleTextAttribute(hConsole, 7);
        c.special2 -= cost;
    }
    return cd;
}
//Fighter 4
int illsign(fighter& tg) {
    int cost = 6, cd = 2;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < tg.spd) {
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
    return cd;
}
int slvsign(fighter& tg) {
    int cost = 3, cd = 1;
    if (d.mana < cost) {
        cout << "Not enough mana! Why are you so BROKE!?\n";
        return -1;
    }
    else {
        if (prng < tg.spd) {
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
    return cd;
}
int eternalmek(fighter& tg) {
    int cost = 12, cd = 3;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        cout << d.name << " throws 4 knives towards " << tg.name << "!\n";
        int tdmg = 0;
        for (int i = 0; i < 4; i++) {
            genrngs();
            if (prng < tg.spd) {
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
    return cd;
}
int lumricochet(fighter& tg) {
    int cost = 55, cd = 10;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        cout << d.name << " launches a VERY powerful knife at " << tg.name << "!\n";
        if (prng < tg.spd) {
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
            int statredrate = 40;
            cout << d.name << "'s knife hits " << tg.name << " and deals " << damage << " damage while reducing their stats by " << statredrate << "%!\n";
            tg.atk -= floor((double)tg.atk * statredrate / 100);
            tg.def -= floor((double)tg.def * statredrate / 100);
            tg.mana -= floor((double)tg.mana * statredrate / 100);
            tg.special -= floor((double)tg.special * statredrate / 100);
        }
        d.mana -= cost;
    }
    return cd;
}
int imagtime(fighter& tg) {
    int cost = 10, cd = 2;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < tg.spd) {
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
    return cd;
}
int fantakiller(fighter& tg) {
    int cost = 22, cd = 4;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
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
    return cd;
}
int soulsculp(fighter& tg) {
    int cost = 11, cd = 3;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < tg.spd) {
            cout << d.name << "'s attack missed!\n";
        }
        else {
            damage = round(mdrng * d.atk) - tg.def;
            if (damage <= 0) {
                cout << d.name << "'s attack hits, but deals 0 damage!\n";
            }
            else {
                tg.hp -= damage;
                cout << d.name << " slashes 28 times at " << tg.name << ", dealing " << damage << " damage!\n";
            }
        }
        d.mana -= cost;
    }
    return cd;
}
int cricochet(fighter& tg) {
    int cost = 40, cd = 10;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        cout << d.name << " throws a purple knife at " << tg.name << "!\n";
        if (prng < tg.spd) {
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
    return cd;
}
int jackdababy(fighter& tg) {
    int cost = 18, cd = 5;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < tg.spd) {
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
    return cd;
}
int lastresort(int& x, fighter& tg) {
    int cost = 15, cd = 15;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        x++;
        SetConsoleTextAttribute(hConsole, 9);
        cout << d.name << " feels cornered...\n";
        SetConsoleTextAttribute(hConsole, 7);
        d.mana -= cost;
    }
    return cd;
}
int sakworld(int& x, fighter& tg) {
    int cost = 20, cd = 10;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < tg.spd) {
            cout << d.name << "'s attack missed!\n";
        }
        else {
            x += 3;
            cout << d.name << " stops time around " << tg.name << " for " << x << " rounds!\n";
        }
        d.mana -= cost;
    }
    return cd;
}
int statsteal(fighter& tg) {
    int cost = 32, cd = 8;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        cout << d.name << " throws 4 knives towards " << tg.name << "!\n";
        int tdmg = 0;
        int k = 0, j = 1;
        for (int i = 0; i < 4; i++) {
            genrngs();
            if (prng < tg.spd) {
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
    return cd;
}
int lunadialII(int& x) {
    int cost = 15, cd = 7;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        x = 1;
        SetConsoleTextAttribute(hConsole, 4);
        cout << d.name << " readies their gold watch!\n";
        SetConsoleTextAttribute(hConsole, 7);
        d.special2 -= cost;
    }
    return cd;
}
int maidassault(fighter& tg) {
    int cost = 6, cd = 2;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        if (prng < tg.spd) {
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
    return cd;
}
int punishment(int& x, fighter& tg) {
    int cost = 30, cd = 11;
    if (d.mana < cost) {
        cout << "Not enough mana!\n";
        return -1;
    }
    else {
        x = 3;
        cout << d.name << " curses " << tg.name << " with " << x << " rounds of overwhelming regrets due to a minor mistake!\n";
        d.mana -= cost;
    }
    return cd;
}
//Fighter 5


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
