#include <cstdio>
#include <list>
#include <vector>
using namespace std;

int main(int argc, char **argv) {

	int n;

	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}

		list<int> card_deque;

		for (int i = 1; i <= n; ++i) {
			card_deque.push_back(i);
		}

		vector<int> discarded_cards;
		discarded_cards.reserve(n * sizeof(int));

		list<int>::iterator it = card_deque.begin();
		while (card_deque.size() >= 2) {
			it = card_deque.begin();
			discarded_cards.push_back(*it);
			card_deque.pop_front();
			it = card_deque.begin();
			int temp = *it;
			card_deque.pop_front();
			card_deque.push_back(temp);
		}

		if (discarded_cards.size() > 0) {
			printf("Discarded cards: ");
			for (int i = 0; i < int(discarded_cards.size()) - 1; ++i) {
				printf("%d, ", discarded_cards[size_t(i)]);
			}
			printf("%d\n", discarded_cards[discarded_cards.size() - 1]);
			printf("Remaining card: %d\n", *it);
		}
		else {
			printf("Discarded cards:\n");
			printf("Remaining card: 1\n");
		}
	}

	return 0;
}


