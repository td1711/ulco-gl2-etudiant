module Net where

-- | Cconnexion avec un identifiant.
data Conn a = Conn
    { _id :: Int
    , _conn :: a
    }

-- | Deux connexions sont égales si elles ont le même identifiant.
instance Eq (Conn a) where
    c1 == c2 = _id c1 == _id c2

-- | Réseau de connexions.
data Net a = Net
    { _nextId :: Int
    , _conns :: [Conn a]
    } deriving (Eq)

-- | Crée un réseau vide.
newNet :: Net a
newNet = Net 0 []

-- | Ajoute une connexion dans le réseau. Retourne le nouveau réseau et le nouvel identifiant créé.
addConn :: a -> Net a -> (Net a, Int)
addConn conn (Net i0 cs0) = (net1, i0)
    where net1 = Net (i0 + 1) (Conn i0 conn : cs0)

-- | Supprime une connexion du réseau, à partir de son identifiant.
rmConn :: Int -> Net a -> Net a
rmConn i net = net { _conns = cs1 }
    where cs1 = filter ((i /=) . _id) (_conns net)

-- | applique une fonction sur toutes les connexions du Manager
mapInNet :: (a -> IO ()) -> Net a -> IO ()
mapInNet f net = mapM_ (f . _conn) (_conns net)
