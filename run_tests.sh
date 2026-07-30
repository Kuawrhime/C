#!/bin/bash
cd "$(dirname "$0")"
for d in anagram clean_str fazzbizz fibonacci_checker french_name_formatter \
         geek_name_formatter gpa_calculator primes_generator scrabble_calculator \
         sort_words spongebob_case_checker text_to_multi_tap us_name_formatter; do
    (cd "$d" && make -s re >/dev/null 2>&1)
done
pass=0; fail=0
chk () { local l="$1" e="$2"; shift 2; local o; o="$("$@" 2>/dev/null | cat -e)"
  if [ "$o" = "$e" ]; then pass=$((pass+1)); else fail=$((fail+1))
  echo "FAIL [$l] attendu=[$e] obtenu=[$o]"; fi; }
rc () { local l="$1" e="$2"; shift 2; "$@" >/dev/null 2>&1
  if [ "$?" = "$e" ]; then pass=$((pass+1)); else fail=$((fail+1))
  echo "FAIL-RC [$l]"; fi; }

chk anagram1 'anagram!$' ./anagram/anagram "Rail Safety" "Fairy tales"
chk anagram2 'no anagrams.$' ./anagram/anagram moo moon
rc  anagram3 84 ./anagram/anagram foobar
chk clean1 'abc cba abc cab cba$' ./clean_str/clean_str "abc cba abc cab cba"
chk clean2 'Remus and Romulus are the two mammals of Rome$' ./clean_str/clean_str \
    " Remus and Romulus are the two mammals of Rome "
chk clean3 'Hello how are you?$' ./clean_str/clean_str "$(printf '\tHello\t\t how are you?\t ')"
chk clean4 '$' ./clean_str/clean_str
chk fazz1 '8$
Bizz$
Fazz$
11$
12$' ./fazzbizz/fazzbizz 8 12
chk fazz2 '89$
FazzBizz$
91$' ./fazzbizz/fazzbizz 89 91
rc  fazz3 84 ./fazzbizz/fazzbizz 2 1
rc  fazz4 84 ./fazzbizz/fazzbizz
chk fib1 'OK$' ./fibonacci_checker/fibonacci_checker 0 1 1 2 3 5 8
chk fib2 'OK$' ./fibonacci_checker/fibonacci_checker 42 84 126 210 336 546 882
chk fib3 'Not a Fibonacci sequence$' ./fibonacci_checker/fibonacci_checker 0 1 1 3
chk fib4 'Not a Fibonacci sequence$' ./fibonacci_checker/fibonacci_checker -1 -1 2
rc  fib5 1 ./fibonacci_checker/fibonacci_checker 0 1 1 3
rc  fib6 0 ./fibonacci_checker/fibonacci_checker 0 1 1 2 3 5 8
rc  fib7 84 ./fibonacci_checker/fibonacci_checker 4242424242 5634118968 9876543210
rc  fib8 84 ./fibonacci_checker/fibonacci_checker 2 4 6 10 16 26GORILLA
rc  fib9 84 ./fibonacci_checker/fibonacci_checker
chk fr1 'Jean-Michel DON DIEGO DE LA VEGA$' ./french_name_formatter/frenchNameFormatter \
    "JeAN-MICHEL don diEgo De la vega"
rc  fr2 84 ./french_name_formatter/frenchNameFormatter
chk geek1 'S4Nt4 T0M4T0!k3tCh2p/ $' ./geek_name_formatter/geekNameFormatter 'santa Tomato!KETCHUP/'
rc  geek2 84 ./geek_name_formatter/geekNameFormatter
chk gpa1 '2.37$' ./gpa_calculator/gpa_calculator A,3 B,2 B,9 E,5
chk gpa2 '1.17$' ./gpa_calculator/gpa_calculator D,20 B,1 C,2
chk gpa3 '2.00$' ./gpa_calculator/gpa_calculator A,6 E,6
chk gpa4 '0.00$' ./gpa_calculator/gpa_calculator D,1 E,1000
rc  gpa5 84 ./gpa_calculator/gpa_calculator
chk prime1 '2$
3$
5$' ./primes_generator/primes_generator 2 5
chk prime2 '23$
19$' ./primes_generator/primes_generator 23 19
chk prime3 '17$
19$
23$
29$' ./primes_generator/primes_generator 14 30
chk prime4 '7$
5$
3$
2$' ./primes_generator/primes_generator 10 1
chk prime5 '' ./primes_generator/primes_generator 90 95
rc  prime6 84 ./primes_generator/primes_generator
V="1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10"
chk scrab1 '8$' ./scrabble_calculator/scrabble_calculator "$V" Hugo
chk scrab2 '18$' ./scrabble_calculator/scrabble_calculator "$V" Chocolatine
rc  scrab3 84 ./scrabble_calculator/scrabble_calculator "$V" system32
rc  scrab4 84 ./scrabble_calculator/scrabble_calculator "$V" ""
rc  scrab5 84 ./scrabble_calculator/scrabble_calculator
chk sort1 'A a b B ca cc cd$' ./sort_words/sort_words "A a b B cc ca cd"
chk sort2 'i just lost my sanity somewhere$' ./sort_words/sort_words \
    "somewhere i     lost just my sanity"
chk sort3 'lost you$' ./sort_words/sort_words "$(printf 'you\t\tlost')"
chk sort4 '$' ./sort_words/sort_words
chk sb1 'OK$' ./spongebob_case_checker/spongebob_case_checker " wHY dO YoU CRaSh? "
chk sb2 'Invalid$' ./spongebob_case_checker/spongebob_case_checker "WELCOME MR. KRABS"
chk sb3 'OK$' ./spongebob_case_checker/spongebob_case_checker \
    "thiS IS = verY   TOuchY! (BUt stILL valID)"
chk sb4 'Invalid$' ./spongebob_case_checker/spongebob_case_checker "H U#G==O"
chk sb5 'OK$' ./spongebob_case_checker/spongebob_case_checker ""
rc  sb6 84 ./spongebob_case_checker/spongebob_case_checker
chk mt1 '222 2333 33$' ./text_to_multi_tap/text_to_multi_tap cafe
chk mt2 '#22244666222666555284446633$' ./text_to_multi_tap/text_to_multi_tap Chocolatine
chk mt3 '#4433555 5556660#96667775553$' ./text_to_multi_tap/text_to_multi_tap "Hello World"
chk mt4 '#2#2#2#44$' ./text_to_multi_tap/text_to_multi_tap AAAH
chk mt5 '$' ./text_to_multi_tap/text_to_multi_tap ""
rc  mt6 0 ./text_to_multi_tap/text_to_multi_tap ""
rc  mt7 84 ./text_to_multi_tap/text_to_multi_tap "pain au choc****"
chk us1 'PJ Harvey$' ./us_name_formatter/USNameFormatter "pJ HARVEY"
chk us2 'Mickael J. Fox$' ./us_name_formatter/USNameFormatter "MiCkAeL j FoX"
rc  us3 84 ./us_name_formatter/USNameFormatter
echo "===== PASS: $pass / $((pass+fail)) ====="
[ "$fail" -eq 0 ]
