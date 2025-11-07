for (int i = 0; i < s.size(); i++) {
                if (s[i] == '1') {
                    sumVal += val[i];
                    for (char ch: words[i])
                        cnt[ch]++;
                }
            }