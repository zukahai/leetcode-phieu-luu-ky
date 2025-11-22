import pandas as pd

def find_invalid_ips(logs: pd.DataFrame) -> pd.DataFrame:
    def invalid_ip(ip):
        octets = ip.split(".")
        if len(octets) != 4:
            return False
        for octet in octets:
            if (int)(octet) > 255 or octet[0] == '0':
                return False
        return True
    result = pd.DataFrame()
    result['ip'] = logs['ip'].apply(lambda x: x if not invalid_ip(x) else -1)
    result = result[result['ip'] != -1]
    result = result.groupby(['ip'])['ip'].count().reset_index(name = 'invalid_count')
    return result.sort_values(by = ['invalid_count', 'ip'], ascending = [False, False]) 