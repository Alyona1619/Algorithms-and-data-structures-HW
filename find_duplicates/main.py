import os
import random
import time


def find_duplicates(files: list[str], hash_function: callable) -> list[str]:
    hashes = {}
    for file in files:
        with open(file, 'rb') as f:
            contents = f.read()
        hash_value = hash_function(contents)
        if hash_value in hashes:
            hashes[hash_value].append(file)
        else:
            hashes[hash_value] = [file]
    duplicates = [files for files in hashes.values() if len(files) > 1]
    return duplicates


def crc_hash(ki):
    h = 0
    for ch in ki:
        highorder = h & 0xf8000000
        h = h << 5
        h = h ^ (highorder >> 27)
        h = h ^ ch
    return h


def pjw_hash(ki):
    h = 0
    for ch in ki:
        h = (h << 4) + ch
        g = h & 0xf0000000
        if g != 0:
            h = h ^ (g >> 24)
            h = h ^ g
    return h


def buz_hash(ki):
    R = [981234567, 765432198, 555555555, 123456789]
    h = 0
    for ch in ki:
        char = chr(ch)
        highorder = h & 0x80000000
        h = h << 1
        h = h ^ (highorder >> 31)
        h = h ^ R[ord(char) % len(R)]
    return h


folder_path = "out"
files = [os.path.join(folder_path, file) for file in os.listdir(folder_path)]

start_time = time.perf_counter()
crc_duplicates = find_duplicates(files, crc_hash)
end_time = time.perf_counter()
print(f"Number of duplicates using CRC hash: {len(crc_duplicates)} ({(end_time - start_time) * 1000} sec)")

start_time = time.perf_counter()
pjw_duplicates = find_duplicates(files, pjw_hash)
end_time = time.perf_counter()
print(f"Number of duplicates using PJW hash: {len(pjw_duplicates)} ({(end_time - start_time) * 1000} sec)")

start_time = time.perf_counter()
buz_duplicates = find_duplicates(files, buz_hash)
end_time = time.perf_counter()
print(f"Number of duplicates using BUZ hash: {len(buz_duplicates)} ({(end_time - start_time) * 1000} sec)")

start_time = time.time()
builtin_duplicates = find_duplicates(files, hash)
end_time = time.time()
print(f"Number of duplicates using built-in hash: {len(builtin_duplicates)} ({(end_time - start_time) * 1000} sec)")
