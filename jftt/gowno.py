import os
import openai

openai.api_key = "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"

response = openai.Completion.create(
  model="text-davinci-003",
  prompt="Używając LEX-a i BISON-a zaimplementuj translator wyrażeń arytmetycznych w ciele\nskończonym o podstawie 1234577 z postaci infiksowej do postaci postfiksowej, z korekcją postaci liczby (w ciele o podstawie p nie ma liczb ujemnych i większych lub równych p), i podającej\nwynik obliczenia wyrażenia. Wyrażenia do policzenia umieszczone są w osobnych liniach.\nProgram ma przetwarzać wszystkie linie wejścia, a linie zaczynające się od # traktować jak\nlinie komentarza i omijać. W przypadku długich linii ma być możliwość ich podzielenie za\npomocą znaku \\ (tak jak w języku c).\nZadbaj o właściwe priorytety operatorów, właściwą łączność operatorów i odpowiednią\nobsługę błędów. Pamiętaj o unarnym operatorze - dla danych wejściowych (często dla\nwygody w ciele o podstawie p piszemy np. (−1) zamiast (p − 1)).",
  temperature=0.7,
  max_tokens=3583,
  top_p=1,
  frequency_penalty=0,
  presence_penalty=0
)