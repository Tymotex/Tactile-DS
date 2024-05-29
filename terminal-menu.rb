# Startup: gotty -w --title-format "Data Structures & Algorithms" ruby terminal 
require "tty-prompt"   
require "colorize"

prompt = TTY::Prompt.new

def is_num(num_given)
    !!Integer(num_given) rescue false
end

begin
  choices = ["Linked List", "Trees", "Graphs", "Heap", "Hash Table", "Sorting Algorithms Timing", "Exit".red]
    choices.map { |choice| choice.blue }
    selection = prompt.select("See the implementations here: https://github.com/Tymotex/Tactile-DS\nWatch a demo here: https://youtu.be/iSJL-9pe-PY\nSelect a data structure:".yellow, choices)
    puts "Starting: %s\n".red % [selection]
    case selection
    when "Linked List"
        system("linked-list/iterative-version/testLinkedList")
    when "Trees"
        treeFlavours = ["Standard Binary Search Tree", "AVL Tree", "Splay Tree"]
        selectedTree = prompt.select("Select tree type:".yellow, treeFlavours) 
        case selectedTree
        when "Standard Binary Search Tree"
            system("binary-tree/testTree")
        when "AVL Tree"
            system("avl-tree/testTree")
        when "Splay Tree"
            system("splay-tree/testTree")
        end
    when "Graphs"
        subtypeWeighted = ["Unweighted", "Weighted"]
        subtypeDirected = ["Undirected", "Directed"]
        graphWeighted = prompt.select("1. Select Weighted/Unweighted".yellow, subtypeWeighted)
        graphDirected = prompt.select("2. Select Directed/Undirected".yellow, subtypeDirected)
        numVertices = prompt.ask("3. How many vertices (1-50)?".yellow, default: "5")
        while (!is_num(numVertices) or (numVertices.to_i > 50 or numVertices.to_i < 1)) do
            if (!is_num(numVertices)) then
                puts "%s isn't an integer. Try again".red % numVertices
            elsif (numVertices.to_i > 50 or numVertices.to_i < 1) then
                puts "%s not in correct range. Try again".red % numVertices
            end
            numVertices = prompt.ask("3. How many vertices (1-50)?".yellow, default: "5")
        end
        case graphWeighted
        when "Unweighted"
            case graphDirected
            when "Undirected"
                system("unweighted-graph/testGraph %d" % numVertices)
            when "Directed"
                system("unweighted-digraph/testGraph %d" % numVertices)
            end
        when "Weighted"
            case graphDirected
            when "Undirected"
                system("weighted-graph/testGraph %d" % numVertices)
            when "Directed"
                system("weighted-digraph/testGraph %d" % numVertices)
            end
        end
    when "Heap"
        heapTypes = ["Max heap", "Min heap"]
        selectedHeapType = prompt.select("1. Select max/min heap".yellow, heapTypes)
        numSlots = prompt.ask("2. How many indices to set for the heap (1-100): ".yellow, default: "10")
        while (!is_num(numSlots) or (numSlots.to_i > 50 or numSlots.to_i < 1)) do
            if (!is_num(numSlots)) then
                puts "%s isn't an integer. Try again".red % numSlots
            elsif (numSlots.to_i > 50 or numSlots.to_i < 1) then
                puts "%s not in correct range. Try again".red % numSlots
            end
            numSlots = prompt.ask("2. How many indices to set for the heap (1-100): ".yellow, default: "10")
        end
        case selectedHeapType    
        when "Max heap"
            system("heap/testHeap --max #{numSlots}")
        when "Min heap"
            system("heap/testHeap --min #{numSlots}")
        end
    when "Hash Table"
        numSlots = prompt.ask("1. How many indices to set for the hash table (1-100): ".yellow, default: "10")
        while (!is_num(numSlots) or (numSlots.to_i > 50 or numSlots.to_i < 1)) do
            if (!is_num(numSlots)) then
                puts "%s isn't an integer. Try again".red % numSlots
            elsif (numSlots.to_i > 50 or numSlots.to_i < 1) then
                puts "%s not in correct range. Try again".red % numSlots
            end
            numSlots = prompt.ask("1. How many indices to set for the hash table (1-100): ".yellow, default: "10")
        end
        system("hash-table/testHash #{numSlots}")
    when "Sorting Algorithms Timing"
        system("sorting-algos/testSort")
    when "Exit"
        puts "Bye!"
    end
rescue SignalException => e
    nil
end
