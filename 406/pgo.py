class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        res = []

        # h값이 가장 사람부터 sort
        people_s = sorted(people, key=lambda people: (-people[0], people[1]))
        # print(people_s)

        # v를 기준으로 insert
        for i, v in people_s:
            res.insert(v, [i, v])

        return res