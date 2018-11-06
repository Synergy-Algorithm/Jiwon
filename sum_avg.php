
//세 명의 학생의 각각 5과목 합과 평균

<?
 $score = array(array(88, 98, 96, 77, 63), array(86, 77, 66, 86, 93), array(74,83, 95, 86, 97));

 $sum =0;
 for( $i = 0; $i < 3; $i++)
 {
         for($j = 0; $j < 5; $j++)
         {
                 $sum = $sum +  $score[$i][$j];
         }
         $avg = $sum / 5;
         echo "sum is $sum, avg is $avg";
         $sum = 0;
 }

?>
