<!-- 
https://github.com/lifeparticle/Markdown-Cheatsheet
https://youtu.be/eVGEea7adDM?si=cz1Fbqxr9VgioIEh
-->

# Math Tutor V5

<b>Table of Content</b>
- [Summary](#summary)
- [Console Output Example](#console-output-example)
- [Maintainers](#maintainers)`

## Summary

    This program will first take the User's name, and then proceed to 
    start a loop process of generating new numbers and math problems 
    for the user, with a leveling system for
    every 3 correct/every 3 fully incorrect answers provided.
    * Initial incorrect answers will give the user 3 chances to correct
     before counting as an actual incorrect answer
    * Each Level adds/subtracts a constant amount to the range of generated
     numbers depending on a Level Up or Level Down
    * Has a Summary at the end to show the user's correct and incorrect answers 
    and averages



## Console Output Testing Example
```
*********************************************************************
*     __  __       _   _       _____      _               _ _ _     *
*    |  \/  | __ _| |_| |__   |_   _|   _| |_ ___  _ __  | | | |    *
*    | |\/| |/ _` | __| '_ \    | || | | | __/ _ \| '__| | | | |    *
*    | |  | | (_| | |_| | | |   | || |_| | || (_) | |    |_|_|_|    *
*    |_|  |_|\__,_|\__|_| |_|   |_| \__,_|\__\___/|_|    (_|_|_)    *
*********************************************************************
*            Welcome to the Silly Simple Math Tutor V2!             *
*********************************************************************

Fun Math Facts:

  * Teaching is hard
  * Math is sometimes hard
  * It gets easier the more you practice
  * Math is fun when it's easy!

********************************************************************

What is your name? <userName>

Welcome, <userName>, to the Silly Simple Math Tutor!

{correct answer loop:}
[Level #1] <userName>, Answer the following: 9 + 3 = <userAnswer:12>

Correct! 12 is the answer!

Do you want to continue? (y=yes | n=no) <userInput:y>

[Level #1] <userName>, Answer the following: 12 / 3 = <userAnswer:4>

Correct! 4 is the answer!

etc...

{if 3 correct questions:}

Correct! <correctAnswer> is the answer!
Level UP!           New Level: 2.
Range UP!           New Range: 1-20.
(scales depending on previous level)

{Incorrect answer loop:}

[Level #2] <userName>, Answer the following: 18 - 6 = <userAnswer:6>

Incorrect! [Attempts Left: 2]
[Level #2] <userName>, Answer the following: 18 - 6 = <userAnswer:4>

Incorrect! [Attempts Left: 1]
[Level #2] <userName>, Answer the following: 18 - 6 = <userAnswer:8>

Incorrect... 12 is the answer...

Do you want to continue? (y=yes | n=no) <userInput:y>
etc...

{if 3 fully incorrect questions:}

Incorrect... <correctAnswer> is the answer...
Level DOWN...           New Level: 1.
Range DOWN...           New Range: 1-10.

{if user doesn't want to continue:}
Do you want to continue?(y=yes | n=no) <userInput:n>
{Example Summary Report:}
====================================
         SUMMARY REPORT
====================================
Level      Question        Attempts
-----  ---------------    ----------
   1     4 - 3  =   1         1
   1     5 + 9  =  14         1
   1    72 / 8  =   9     Incorrect
   1     3 * 3  =   9     Incorrect

Total Questions:     4
Total Correct  :     2
Total Incorrect:     2
Average Correct:     50%

Thanks for playing!



End of program.

```

## Maintainers
[@SamuelRob86](https://github.com/SamuelRob86) Samuel Robinson

[@davy-tran](https://github.com/davy-tran) Davy Tran

[Back to Top](#math-tutor-v1)


