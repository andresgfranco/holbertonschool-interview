#!/usr/bin/python3
"""This module contains the count_words function"""

import requests


def print_greater_than_zero(word_counter):
    """print all keys and values grater than zero
    """
    keys = list(word_counter.keys())

    keys.sort()

    for k in keys:
        v = word_counter[k]
        if v > 0:
            print("{}: {}".format(k, v))


def count_words(subreddit, word_list, after="", word_counter={}):
    """queries the Reddit API,
    """
    if after == "":
        for i in range(len(word_list)):
            word_list[i] = word_list[i].lower()
            word_counter[word_list[i]] = 0

    if after is None:
        print_greater_than_zero(word_counter)
        return

    headers = {"user-agent": "myapp/v0.1"}
    url = f"https://www.reddit.com/r/{subreddit}/hot.json?after={after}"

    try:
        res = requests.get(url, headers=headers)

        json_data = res.json().get("data")
        after = json_data.get("after")

        childrens = json_data.get("children")

        for children in childrens:
            title = children.get("data").get("title").split()

            for j in title:
                j = j.lower()
                if j in word_counter.keys():
                    word_counter[j] += 1

        count_words(subreddit, word_list, after, word_counter)
    except Exception:
        return
