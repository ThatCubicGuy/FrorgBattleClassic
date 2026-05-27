# FrorgBattleV1
In a time long, long before frorgbattleV2, there was this. The original, gigantic mess of a C++ program known at the time only as FrorgBattle. To be perfectly honest, this is still a fun game. As wonky and completely unbalanced in some parts as it may be, it has its charm due to just how many abilities each character has and how varied their effects are (well, for some characters). It also has the most "personalization" that any game will ever have again, by virtue of things like "Not enough mana" messages and cost and cooldowns and even damage calculations and dealing ALL being written and checked and deducted MANUALLY in each ability.
### Short history
I wrote this program in the vacation between 9th and 10th grade, after having experienced about a semester of C++, with no prior coding experience outside of a cool HTML course in 5th grade and JavaScript in 6th grade. But I made this anyway. Why did I make this?
Me and my cousin were extremely bored one time on discord and just started using characters like 𓆏 and ඞ to communicate, and made them fight each other. "𓆏 fires a tornado at ඞ! ඞ took 200 damage!!". "ඞ counterattacks for 999 damage!!!!". Stuff like that. And I decided, hey! This "programming" thing I'm learning in highschool seems perfect for this! And so, FrorgBattle was born.

# Abilities

## f r o r g
```yml
1. UNO Reverse Card - Reflect everything about a spell. [25 Mana]
2. Lottery Ticket - Feeling lucky? This could deal 10x your ATK! Among other things. [15 Luck]
3. 3st - Drain 10 Mana from your opponent to use for your following attacks. [20 Luck]
4. Bitch Slap - Epic bitch slap, ignores DEF and does medium damage twice. [16 Mana]
5. BLLUUUEEAAAGHH - Barf on your enemies, resulting in heavy damage along with -5 ATK. [15 Mana]
6. Little Misfortune - Feeling more lucky than the other? Do 5 times your Luck in damage. [36 Mana]
7. Wake up, lieutenant! - Slap the living shit out of your enemies. Deals 10% of your ATK 20 times. [15 Mana]
8. Ofaka Tornado - All enemies' stats -20. [40 Mana]
9. British summer time - Rain starts pouring over the battlefield for 3 rounds. Per round >>> +15 Mana for you, +30 HP for you, -10 HP for enemies, -5 ATK for enemies. [31 Mana]
10. Lucky slice - Deals medium damage which is then converted into luck with a 2:1 ratio. [9 Mana]
11. BABABOOEY. - Launches a cat sitting on a toilet around the universe. If you're lucky, it'll hit for heavy damage and -1 SPD. [15 Mana]
12. boioioioioioioing - Shove your enemy so far it takes them another 2 rounds to get back to where you were. Light damage. [18 Mana]
13. qryqwtyqtwtyweoirtyuotweriutwoeprty - Gives your opponent a brain anneurysm, resulting in loss of all special stats. [25 Mana]
14. Ghost not busted - Trick your opponent into using a random spell next round. [10 Mana]
15. Cave Johnson's advice - Life gave you lemons, but you didn't make lemonade. You got MAD! [41 Mana]
```
```yml
Phase 2: You're no longer a regular frog. You don't need Mana for your attacks anymore, but Angery. When you get hit, you get 1 Angery.
```
```yml
16. A good bloody bludgeoning - If ATK > 90, do medium damage 3x. Ignores DEF. ==3 Angery==
17. Frogstuffs - Ingest your enemies. 10% of their stats get transported to you. Light damage. ==2 Angery==
18. SHUTUPSHUTUPSHUTUPSHUTUP - Silence your enemies. Cannot use mana for the following round. ==4 Angery==
19. DieDieDieDie - 4 Consecutive smacks. 0.3x ATK per smack. ==1 Angery==
20. fin - Channel all your anger into one giant "Fuck You". Massive damage. ==10 Angery==
```

## TODD
```
𓆏~You will die not knowing what this power is

1.Multislash. 𓆏's knife glows dark red as he slashes 4 times, creating 4 dark red projectiles that are frozen in mid-air
His knife then flashes to red and he fires off all the slashes at once, which slightly home in on the opponent.light damage.4 mana.

2.Sharp Precision.𓆏 throws several knives at his opponent, dealing light damage. 3 mana

3.soulshatter. 𓆏 brings out 2 knives before he waves his arms, unleashing a flurry of red slashes at a blinding speed. He  hover slightly while using the move and same goes for the opponent if hit. Deals medium damage. 15 mana

4. Illusion Existence: "Clock Corpse".𓆏 shoots out blue magic orbs in an AOE before freezing time around him as he summons knives near close by opponents. heavy damage. 20 mana
 
5.Pocket Watch Of Blood. 𓆏 trows a pocket watch at the enemy dealing medium damage. The damage taken from the enemy will be added to 𓆏 even if exceeds 𓆏 hp. (1000 + 20 = 1020 EXAMPLE) 17 mana 
6. Determination Unleashed. 𓆏  will teleport behind the foe and plant his sword into the ground, causing a red beam to fall from the sky at his location, then a large AOE explosion will occur that gains more power the closer you are to the center. Heavy damage. 18 mana 
7.Patience Slam.𓆏  knife glows light blue as he points it forward, sending out a light blue rope at the opponent. If it hits, he pulls them overhead and slams them down, dealing medium damage. 10 mana
8.Kindness Heal.  𓆏  knife glows green as he raises it up, healing 200 HP. 15 mana

Phase 2~Not yet ( increase mana to 150) 
9.ACT = [Summon_Knives]. 𓆏 slashes upwards. If he hits a target, they are launched into the air for 4 damage as he summons and presses the OVERWRITE button summoning his knives, heavy damage. 20 mana
10. time paradox. 𓆏 distorts time for a brief moment and leaps backwards, allowing him to escape a combo or a move. 15 mana 
11. Knife Storm.𓆏 teleports both himself and the opponent into the sky. As they fall, 𓆏 will summon several knives before launching them at the target.
𓆏 then teleports himself and the opponent back to the place the move was first used and launches more knives, which will begin slashing at the target in a blizzard movement. 25 mana 
𝖗𝖆𝖚𝖑 [RE],  — 25/06/2022 17:48
12. RO-TA-TE.𓆏 jumps in the air doing rotate rotate and trowing knifes. massive damage 30 mana
13. Karma Is A Beach. The enemy will lose 10% of its hp and wont be able to heal for the next 5 rounds. 20
14.Not My DNA. 𓆏 uses a random spell from the enemy 15 mana 
15. TITUTU BACK-BACK-BACKSTABBER TUTUTU STAB HIM? STAB HIM!. 𓆏 backstabs the enemy taking 5% health and 10% mana- 25 mana
```
TL;DR:
```yml
1. Light damage [4 Mana]
2. Light damage [3 Mana]
3. Medium damage [15 Mana]
4. Heavy damage, undodgeable [20 Mana]
5. Medium damage, lifesteal [17 Mana]
6. Heavy damage, undodgeable [18 Mana]
7. Medium damage [10 Mana]
8. Heal, 300 HP [25 Mana]
```
```cs
[PHASE 2]
9. Heavy damage [5 FEAR]
10. Counter [15 FEAR]
11. 1.5x Medium damage, +10% HATE [10 FEAR]
12. Heavy damage, up to 5 times [25 FEAR]
13. Karma damage, deny healing [15 FEAR]
14. Steal a spell [15 FEAR]
15. Heavy damage, lifesteal, DEF Reduction [25 FEAR]
```

## Player
```yml
1.Fake teleport. while doing the teleport animation, the player summons a big slash dealing medium damage. [6 MANA]
2.dark blaster. Uses a black gaster blaster dealing medium damage [6 MANA]
3.creepvine. summons 10 hands that shoots vines at the enemy stunning them for 2 rounds [18 MANA]
4.multi blaster.summons 5 blasters . heavy damage [14 MANA]
5.phanto-trow.trows the phantom blade at the enemy. if hit the enemy will be pushed back and player will recieve [10 MANA]. medium damage  [9 MANA]
6.realo-kinfo. spawns a fake real knife that stabs the enemy.light damage [3 MANA]
7.serious problem. spawn a codded real knife that have the size of 99. deals heavy damage [13 MANA]
8.shut up.player got mad. he is cursing the enemy for 3 rounds. player will get 10 hp. [15 MANA] and 3 def and 1 spd while the enemy will lose those stats [60 MANA]
```
phase 2. ~you are in for a treat
```yml
9.wanna know what just hapened? mosters above this fun magical world are all my friends. you didnt show any mercy to them SO DONT YOU DARE THINK ANYONE WILL SHOW MERCY TO YOU NOW. Massive damage [31 MANA]
10.Code stealer. Steals the enemys code and deletes a random spell for 5 rounds [17 MANA]
11. BORING.player is bored so he buffs himself by 10% (all stats) [40 MANA]
12.{ACT}DELETE.delets the enemys next attack [22 MANA]
```

## Sakuya
1. Medium damage: 6mp, 2cd
2. Light damage: 3mp, 1cd
3. 4*Light damage: 12mp, 3cd
4. Heavy damage & -40% all: 55mp, 10cd
5. Medium damage: 10mp, 2cd
6. Heavy damage undodgeable: 22mp, 4cd
7. Medium damage: 11mp, 3cd
8. 3*Medium damage: 40mp, 10cd
9. Medium damage & -def: 18mp, 5cd
10. Counter +500hp: 25mp, 13cd
11. Stun 2rnd: 20mp, 10cd
12. Statsteal knives: 32mp, 8cd
13. Dodge: 15mp, 7cd
14. Medium damage: 6mp, 2cd
15. Rain: 30mp, 11cd