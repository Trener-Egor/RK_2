#include <cstdint>
#include <iostream>
#include <unordered_map>

#include "gtest/gtest.h"

namespace jc {

class Memento {
 public:
  Memento(std::int32_t n = 0) : value_(n) {}

  std::int32_t Value() const { return value_; }

 private:
  std::int32_t value_;
};

class Originator {
 public:
  Originator(std::int32_t n = 0) : value_(n) {}

  Memento ValueMemento() const { return Memento{value_}; }

  void Load(const Memento& m) { value_ = m.Value(); }

  void PrintValue() const { std::cout << value_ << '\n'; }

  void SetValue(std::int32_t n) { value_ = n; }

 private:
  std::int32_t value_;
};

class Caretaker {
 public:
  Memento& State(const std::string& s) { return mementos_.at(s); }

  void SetState(const std::string& s, const Memento& m) {
    mementos_.try_emplace(s, m);
  }

 private:
  std::unordered_map<std::string, Memento> mementos_;
};

}  

namespace jc {

 TEST(MementoTest, ValueIsCorrect) {
   Memento memento(5);
   ASSERT_EQ(memento.Value(), 5);
}

TEST(OriginatorTest, SaveAndLoadMemento) {
   Originator originator(10);
   Memento memento = originator.ValueMemento();
   
   originator.SetValue(20);
   originator.Load(memento);
   
   ASSERT_EQ(originator.ValueMemento().Value(), 10);
}

TEST(CaretakerTest, SaveAndLoadState) {
   Caretaker caretaker;
   Originator originator(30);
   
   caretaker.SetState("test", originator.ValueMemento());
   originator.SetValue(40);

   originator.Load(caretaker.State("test"));
   
   ASSERT_EQ(originator.ValueMemento().Value(), 30);
 }

}  // namespace jc



int main(int argc, char** argv) 
{
  std::cout << "TIMP's RK_2\n";

  jc::Caretaker caretaker;
  
  jc::Originator originator(1);
  caretaker.SetState("one", originator.ValueMemento());
  
  originator.SetValue(2);
  caretaker.SetState("two", originator.ValueMemento());
  
  originator.SetValue(3);
  caretaker.SetState("three", originator.ValueMemento());


  originator.Load(caretaker.State("two"));
  originator.PrintValue();  // 2
  originator.Load(caretaker.State("one"));
  originator.PrintValue();  // 1
  originator.Load(caretaker.State("three"));
  originator.PrintValue();  // 3


  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}
