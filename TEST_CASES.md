# Test Cases for Array Operations Program

## Test 1: Basic Operations
**Input:** [45, 12, 89, 23, 67]
**Expected Results:**
- Display: [45, 12, 89, 23, 67]
- Minimum: 12
- Maximum: 89
- Average: 47.20

## Test 2: Sorting
**Input:** [45, 12, 89, 23, 67]
**Action:** Sort array
**Expected Result:** [12, 23, 45, 67, 89]

## Test 3: Reversing
**Input:** [10, 20, 30, 40, 50]
**Action:** Reverse array
**Expected Result:** [50, 40, 30, 20, 10]

## Test 4: Search Found
**Input:** [5, 10, 15, 20, 25]
**Search Value:** 15
**Expected Result:** Element 15 found at index 2

## Test 5: Search Not Found
**Input:** [5, 10, 15, 20, 25]
**Search Value:** 99
**Expected Result:** Element 99 not found in the array

## Test 6: Single Element
**Input:** [42]
**Expected Results:**
- Display: [42]
- Minimum: 42
- Maximum: 42
- Average: 42.00

## Test 7: All Same Elements
**Input:** [7, 7, 7, 7, 7]
**Expected Results:**
- Minimum: 7
- Maximum: 7
- Average: 7.00
- After Sort: [7, 7, 7, 7, 7]

## Test 8: Negative Numbers
**Input:** [-5, -10, -1, -20, -3]
**Expected Results:**
- Minimum: -20
- Maximum: -1
- Average: -7.80
- After Sort: [-20, -10, -5, -3, -1]

## Test 9: Mixed Positive and Negative
**Input:** [-10, 5, -3, 15, 0]
**Expected Results:**
- Minimum: -10
- Maximum: 15
- Average: 1.40
- After Sort: [-10, -3, 0, 5, 15]

## Test 10: Edge Case - Large Array
**Input:** Create array with 100 elements (1 to 100)
**Expected Results:**
- Minimum: 1
- Maximum: 100
- Average: 50.50
