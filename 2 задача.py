    import sys
     
    def main():
        data = sys.stdin.read().split()
        if len(data) < 2:
            return
        
        s1 = data[0]
        s2 = data[1]
        
        if len(s1) != len(s2):
            print(-1)
            return
            
        n = len(s1)
        s = s1 + "#" + s2 + s2
        pi = [0] * len(s)
        
        for i in range(1, len(s)):
            j = pi[i - 1]
            while j > 0 and s[i] != s[j]:
                j = pi[j - 1]
            if s[i] == s[j]:
                j += 1
            pi[i] = j
            
            if pi[i] == n:
                print(i - 2 * n)
                return
                
        print(-1)
     
    if __name__ == '__main__':
        main()

