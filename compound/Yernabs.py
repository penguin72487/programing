from decimal import Decimal, getcontext
import math

# 設定小數點後50位精度
getcontext().prec = 51

def total_apr(S0, ratio, Fee, slip, total_seconds, A):
    S0 = Decimal(S0)
    ratio = Decimal(ratio)
    Fee = Decimal(Fee)
    slip = Decimal(slip)
    total_seconds = Decimal(total_seconds)
    A = Decimal(A)
    r = ratio / total_seconds
    time = total_seconds
    p = S0
    if A / (p * r) > time:
        return Decimal(-1.0) * A / (p * r)
    while time >= A / (p * r):
        time -= A / (p * r)
        p = p + A - Fee
    return p + p * r * time - Fee

def main():
    v = [
        ("ATOM", Decimal('41.5'), Decimal('0.1699'), Decimal('0.06'), Decimal('0')),
        ("ADA", Decimal('1735'), Decimal('0.0303'), Decimal('0.2'), Decimal('0')),
        ("SUI Scallop", Decimal('2458.84'), Decimal('0.63'), Decimal('0.04'), Decimal('0')),
        ("SUI Bucket", Decimal('330'), Decimal('0.3'), Decimal('0.06'), Decimal('0'))
    ]
    total_seconds = 365 * 24 * 60 * 60  # 一年的秒數
    jump = Decimal('0.0000001')

    for name, S0, ratio, Fee, slip in v:
        S0 = Decimal(S0)
        ratio = Decimal(ratio)
        Fee = Decimal(Fee)
        slip = Decimal(slip)
        max_value = S0
        op = Decimal('0.0')
        ed = S0
        while op <= ed:
            mid = (op + ed) / Decimal('2.0')
            tmpl = total_apr(S0, ratio, Fee, slip, total_seconds, mid - jump)
            tmp = total_apr(S0, ratio, Fee, slip, total_seconds, mid)
            tmpr = total_apr(S0, ratio, Fee, slip, total_seconds, mid + jump)
            if tmpl < tmp and tmp < tmpr:
                op = mid + jump
            elif tmpl > tmp and tmp > tmpr:
                ed = mid - jump
            elif tmpl < tmp and tmp > tmpr:
                op = mid
                break
            else:
                print("0")
            if max_value < tmp:
                max_value = tmp
        print(f"{name}")
        print(f"Accumulated A {op + Fee:.50f} T1 = {(op + Fee) * total_seconds / (S0 * ratio) / Decimal('86400.0'):.50f} days")
        print(f"Initial value: {S0} Max value: {max_value:.50f}")
        print(f"Original APY: {ratio * Decimal('100.0'):.50f}% APY: {(max_value - S0) / S0 * Decimal('100'):.50f}% Max APY: {Decimal(math.exp(ratio)) * Decimal('100.0') - Decimal('100.0'):.50f}%\n")

if __name__ == "__main__":
    main()
