import random
global top
top = -1
k = 0

def push(stack, MAX, val):
    global top
    if top >= MAX - 1:
        print('[stack is full!]')
    else:
        top = top + 1
        stack[top] = val

def pop(stack):
    global top
    if top < 0:
        print('[stack is empty!]')
    else:
        top = top - 1
        return stack[top + 1]

def shuffle(old):
    result = []
    while old:
        p = random.randrange(0, len(old))
        result.append(old[p])
        old.pop(p)
    return result

card = [None] * 52
card_new = [None] * 52
stack = [0] * 52
for i in range(52):
    card[i] = i + 1
print('[wait...]')
card_new = shuffle(card)
i = 0
while i != 52:
    push(stack, 52, card_new[i])
    i = i + 1
print('dealing...')
print('show card\nEast\tSouth\tWest\tNorth')
print("==========================================")
while top >= 0:
    style = (stack[top]) % 4
    if style == 0:
        ascVal = 'club'
    elif style == 1:
        ascVal = 'diamond'
    elif style == 2:
        ascVal = 'heart'
    elif style == 3:
        ascVal = 'spade'
    print('[%s%3d]\t' % (ascVal, stack[top] % 13 + 1), end='')
    if top % 4 == 0:
        print()
    top -= 1
