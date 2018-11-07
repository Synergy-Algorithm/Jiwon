#!/usr/bin/php


//단어의 시작 문자의 알파벳 개수와 단어의 끝 문자 알파벳 개수

<?
 $fp = fopen("/home/user/Desktop/words.txt", "r+");
 if(!$fp)
 {
     echo "Error!";
 }
 $alpha = array(
     array('a', 0),
     array('b', 0),
     array('c', 0),
     array('d', 0),
     array('e', 0),
     array('f', 0),
     array('g', 0),
     array('h', 0),
     array('i', 0),
     array('j', 0),
     array('k', 0),
     array('l', 0),
     array('m', 0),
     array('n', 0),
     array('o', 0),
     array('p', 0),
     array('q', 0),
     array('r', 0),
     array('s', 0),
     array('t', 0),
     array('u', 0),
     array('v', 0),
     array('w', 0),
     array('x', 0),
     array('y', 0),
     array('z', 0));
 while(!feof($fp))
 {
     $temp = fgets($fp);
     for($i=0; $i <26; $i++)
     {
         if($alpha[$i][0] == strtolower(substr($temp, 0, 1)))
         {
             $alpha[$i][1] = $alpha[$i][1] + 1;
             break;
         }
     }
 }

 foreach($alpha as $item)
 {
     echo "$item[0] = $item[1]\n";
 }

 for($i = 0; $i < 26; $i++)
     $alpha[$i][1] = 0;
 
 echo "\n";
 $fp1 = fopen("/home/user/Desktop/words.txt", "r");
 while(!feof($fp1))
 {
     $temp = fgets($fp1);
     for($i=0; $i < 26; $i++)
     {
         if($alpha[$i][0] == strtolower(substr($temp,-3, 1)))
         {
             $alpha[$i][1] = $alpha[$i][1] + 1;
             break;
         }
     }
 }

 foreach($alpha as $item)
 {
     echo "$item[0] = $item[1] \n";
 }


 

 fclose($fp);
 fclose($fp1);
?> 