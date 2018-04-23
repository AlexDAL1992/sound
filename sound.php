<?php
$log_file = "sound_log.txt";
$data = $_POST["data"];
$today = date("Y-m-d H:i:s");
$str = $today.", ".$data."\n";

if(file_exists($log_file)){
	$fp = fopen($log_file, a); // the file is opened as append mode
	fwrite($fp, $str);
	fclose($fp);
}else{ // if the file doesn't exist, create a new file
	$fp = fopen($log_file, w); // the file is opened as write mode
	fwrite($fp, $str);
	fclose($fp);
}
echo "Data is stored.\n";
?>
