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
