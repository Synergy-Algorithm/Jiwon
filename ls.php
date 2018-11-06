#!/usr/bin/php
// 유닉스 명령 ls -aFl /root를 파일과 디렉토리 숫자를 세고 파일과 디렉토리 이름, 크기, 권한을 표시해주는 프로그램


<?
 $ls1 = popen('ls -aFl /root', 'r');
 $read = fread($ls1, 4096);
 print_r($read);
 $str = explode("\n", $read);
 $result = "";
 $directory_num = 0;
 $file_num = 0;
 foreach($str as $item)
 {
     $item1 = explode(" ",$item);
     $item1 = array_filter($item1);
     $item1 = array_values($item1);

     if(substr($item1[0],0, 1) == 'd'&& substr($item1[8], -2) != './')
     {
         $directory_num = $directory_num + 1;
         $result = $result."$item1[8] $item1[4] $item1[0]\n";
     }
     else if(substr($item1[0],0,1) == "-" && substr($item1, -2) != './')
     {
         $file_num = $file_num +1;
         $result = $result."$item1[8] $item1[4] $item1[0] \n";
     }
     

 }
 echo "directory = $directory_num, file = $file_num \n";
 echo $result;


 pclose($ls1);
?> 