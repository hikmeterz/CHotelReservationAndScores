﻿# CHotelReservationAndScores

## Project Description
This repository contains C programs for managing hotel reservations and player scores. Each program addresses a specific task related to these topics, including reading reservations, finding top scores, updating scores, and deleting scores.

## Files
- `q1.c`: C program for reading and managing hotel reservations.
- `q2.c`: C program for finding the top k player scores.
- `q3.c`: C program for updating player scores.
- `q4.c`: C program for deleting specific player scores.
- `reservations.txt`: Sample input file for hotel reservations.
- `players.txt`, `updated_scores_q.txt`, `updated_scores_q3.txt`, `updated_scores_q4.txt`: Sample input and output files for player scores.

## C Program Descriptions

### `q1.c`
This C program reads a file containing hotel reservations and stores the information in an array of structures. The program defines two structures, `date` and `reservation`, to manage reservation data. It includes a function `readReservationFile` to read the file and populate the structure array.

#### Key Features:
- Reads reservation data from `reservations.txt`.
- Stores the data in an array of structures.
- Prints the reservation details.

#### Example Input (reservations.txt)
<res.id> <first name> <last name> <check in date> <check out date> <room #>
1344 Antione Hamill 15 10 2020 20 10 2020 1
1235 Delores Balser 12 11 2020 13 11 2020 1
546 Shante Burkhead 01 12 2020 09 12 2020 1
6856 Tiffiny Wimberley 25 11 2020 03 12 2020 2
7524 Lamont Harper 15 10 2020 19 10 2020 3
46 Kera Indelicato 02 11 2020 09 11 2020 3
1232 Laureen Cairo 31 10 2020 02 11 2020 2
7567 Lavada Stegner 25 12 2020 05 01 2021 3
8343 Brandi Ponce 31 10 2020 02 11 2020 1
5857 Miquel Husain 15 10 2020 20 10 2020 2

### `q2.c`
This C program reads a file containing player scores and outputs the top k scores along with their corresponding player names in descending order. The program takes the file name and integer k as input from the console.

#### Key Features:
- Reads player scores from an input file.
- Outputs the top k scores in descending order.

#### Example Input (players.txt)
Player Score
Aynur 900
Bekir 550
Ayse 300
Sultan 300
Erman 1200
Ekim 100
Timur 990
Sule 550

#### Example Console Input
Enter file name: players.txt
Enter k: 3
#### Example Output

Erman 1200
Timur 990
Aynur 900
### `q3.c`
This C program updates player scores by replacing old scores with new scores. The program prompts the user to enter a filename, old score, and new score. It writes the updated scores to another file named `updated_scores_q3.txt`.

#### Key Features:
- Reads player scores from an input file.
- Replaces old scores with new scores.
- Writes the updated scores to `updated_scores_q3.txt`.

#### Example Input (players.txt)

Player Score
Aynur 900
Bekir 550
Ayse 300
Sultan 300
Erman 1200
Ekim 100
Timur 990
Sule 550

#### Example Console Input

Enter file name: players.txt
Enter old score: 300
Enter new score: 400

#### Example Output (updated_scores_q3.txt)

Player Score
Aynur 900
Bekir 550
Ayse 400
Sultan 400
Erman 1200
Ekim 100
Timur 990
Sule 550

### `q4.c`
This C program deletes specific player scores. The program prompts the user to enter a filename and score s. It removes all players with the specified score and writes the remaining players and their scores to another file named `updated_scores_q4.txt`.

#### Key Features:
- Reads player scores from an input file.
- Deletes players with the specified score.
- Writes the remaining scores to `updated_scores_q4.txt`.

#### Example Input (players.txt)

Player Score
Aynur 900
Bekir 550
Ayse 300
Sultan 300
Erman 1200
Ekim 100
Timur 990
Sule 550
#### Example Console Input

Enter file name: players.txt
Enter score to delete: 550

#### Example Output (updated_scores_q4.txt)

Player Score
Aynur 900
Ayse 300
Sultan 300
Erman 1200
Ekim 100
Timur 990


