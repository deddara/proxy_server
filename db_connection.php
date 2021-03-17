<?php
$servername = "127.0.0.1:3305";
$username = "deddara";
$password = "deddara";

// Create connection
$conn = new mysqli($servername, $username, $password);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully\n";

if ($result = $conn->query("SELECT user FROM mysql.user")) {
$result->data_seek(1);
    $row = $result->fetch_row();
    printf("User: %s \n", $row[0]);
}


?>