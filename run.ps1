$length = $args[0];
$cards = '';
for ($i = 0; $i -lt $length; $i++) {
    $card = 'W', 'E', 'F', 'A' | get-random;
    $cards += $card;
}
$input = $length.toString() + $cards;
echo "Input: " $input;
$result = echo $input | ./build/main.exe;
echo "Output: " $result;
if (($result -like '*FW*') || ($result -like '*WF*') || ($result -like '*AE*') || ($result -like '*EA*')) {
    echo "Invalid Output.";
} else {
    echo "Valid Output.";
}
 