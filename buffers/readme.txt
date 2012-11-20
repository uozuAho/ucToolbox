This dir contains different types of buffers, mainly intended for low level use.
I just read that STL sets/queues etc. are not thread-safe which I think means are
also not safe for ISRs. I intend to use these buffers in ISRs - so NO STL HERE!!