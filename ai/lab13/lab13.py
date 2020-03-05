import nltk
import nltk.tag.brill
from nltk.corpus import brown

nltk.download("brown")
nltk.download("universal_tagset")
#prepare data
brown_tagged_sents = brown.tagged_sents(categories='news', tagset='universal')
brown_sents = brown.sents(categories='news')
size = int(len(brown_tagged_sents) * 0.9)
train_sents = brown_tagged_sents[:size]
#set up first stage of tagging
backoff = nltk.RegexpTagger([
    (r'^[A-Z]+.*$', 'NOUN'),           # proper nouns
    (r'^-?[0-9]+(.[0-9]+)?$', 'NUM'),  # cardinal numbers
    (r'(The|the|A|a|An|an)$', 'DET'),  # articles
    (r'.*able$', 'ADJ'),               # adjectives
    (r'.*ness$', 'NOUN'),              # nouns formed from adjectives
    (r'.*ly$', 'ADV'),                 # adverbs
    (r'.*s$', 'NOUN'),                 # plural nouns
    (r'.*ing$', 'VERB'),               # gerunds
    (r'.*ed$', 'VERB'),                # past tense verbs
    (r'.*', 'NOUN')                    # nouns (default)
    ])
baseline_tagger = nltk.UnigramTagger(train_sents, backoff=backoff)
#set up second stage of tagging 
tt = nltk.tag.brill_trainer.BrillTaggerTrainer(baseline_tagger, nltk.tag.brill.brill24())
brill_tagger = tt.train(train_sents, max_rules=15)
#evaluation
print(brill_tagger.rules())
print(brill_tagger.tag(brown_sents[2007]))
print(brill_tagger.evaluate(brown_tagged_sents[size:]))
