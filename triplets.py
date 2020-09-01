"""
Given an array of n integers, are there elements a, b, c in the array such that add up to a target sum. 
Find all unique triplets in the array which give the sum of zero. (i.e. a + b + c = 0)
in = [7, 12, 3, 1, 2, -6, 5, -8, 6]

result = [(7, 1, -8), (3, 5, -8), (1, -6, 5), (2, -8, 6)]

Learning: Dedupe triplets using smallest number.
"""

def find_triplets(input):
    length = len(input)

    all_pairs = []
    # Assume unique input
    # Find unique pairs
    for i in range(0, length-1):
        for j in range(i+1, length):
            all_pairs.append([input[i], input[j]])
    print all_pairs

    all_dict = dict()
    for i in range(0, length):
        all_dict[input[i]] = True
    print all_dict

    for pair in all_pairs:
        sum = pair[0] + pair[1]
        target = -1 * sum
        if target in all_dict and (target != pair[0] and target != pair[1]) and (target < pair[0] and target < pair[1]):
            print("Found triplet %s %s %s" % (pair[0], pair[1], target))
       



find_triplets([7, 12, 3, 1, 2, -6, 5, -8, 6])
#find_triplets([7, 12, 3, 1, 2])